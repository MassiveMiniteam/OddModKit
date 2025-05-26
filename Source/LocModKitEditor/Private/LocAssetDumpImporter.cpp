// Fill out your copyright notice in the Description page of Project Settings.


#include "LocAssetDumpImporter.h"

#include "AssetToolsModule.h"
#include "EdGraphSchema_K2_Actions.h"
#include "K2Node_ComponentBoundEvent.h"
#include "K2Node_CustomEvent.h"
#include "K2Node_FunctionEntry.h"
#include "K2Node_FunctionResult.h"
#include "MovieScene.h"
#include "SAssetDumpImporter.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Factories/BlueprintFactory.h"
#include "Serialization/ObjectAndNameAsStringProxyArchive.h"
#include "NiagaraSystem.h"
#include "NiagaraScript.h"
#include "NiagaraScriptSource.h"
#include "ObjectTools.h"
#include "WidgetBlueprintEditorUtils.h"
#include "Animation/WidgetAnimation.h"
#include "Blueprint/WidgetTree.h"
#include "Editor/UMGEditor/Public/WidgetBlueprint.h"
#include "Engine/SCS_Node.h"
#include "Engine/SimpleConstructionScript.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "UObject/SavePackage.h"

void ULocAssetDumpImporter::ImportAssetDump(FString Path, TArray<FAssetData> InDataToOverwrite)
{
	TArray<uint8> Bytes;
	FFileHelper::LoadFileToArray(Bytes, *Path);

	TSharedPtr<FAssetDumpFile> DumpFile = MakeShareable(new FAssetDumpFile);
	
	FMemoryReader ActorWriter(Bytes, false);
	FObjectAndNameAsStringProxyArchive Archive(ActorWriter, true);
	Archive.SetIsLoading(true);
	Archive << *DumpFile;

	if (InDataToOverwrite.Num() > 0)
	{
		for (FAssetData& Data : InDataToOverwrite)
		{
			TArray<FAssetData> ToOverride = { Data };
			OverwriteData(DumpFile, ToOverride);
		}
	}
	else
	{
		OpenAssetDumpImporter(DumpFile);
	}
}

void ULocAssetDumpImporter::CreateAssetDummies(TArray<FAssetDumpEntry>& OrderedAssetsToCreate)
{
	TMap<int, UBlueprint*> Blueprints;
	for (int i = OrderedAssetsToCreate.Num() - 1; i >= 0; i--)
	{
		auto& ToCreate = OrderedAssetsToCreate[i];
		UE_LOG(LogTemp, Log, TEXT("CREATE %s"), *(ToCreate.PackagePath / ToCreate.AssetName.ToString()));
		UObject* Obj = CreateAssetForAssetEntry(ToCreate);
		if (IsValid(Obj))
		{
			UBlueprint* Blueprint = Cast<UBlueprint>(Obj);
			if (IsValid(Blueprint))
			{
				Blueprints.Add(i, Blueprint);
			}
		}
	}

	for (auto Blueprint : Blueprints)
	{
		UE_LOG(LogTemp, Log, TEXT("FINISH CREATING %s"), *Blueprint.Value->GetName());
		FinishCreateBlueprintAsset(Blueprint.Value, OrderedAssetsToCreate[Blueprint.Key]);
	}
}

void ULocAssetDumpImporter::ImportAssetDumpWithFileList(FString Path, TArray<FString> Files)
{
	TArray<uint8> Bytes;
	FFileHelper::LoadFileToArray(Bytes, *Path);

	TSharedPtr<FAssetDumpFile> DumpFile = MakeShareable(new FAssetDumpFile);
	
	FMemoryReader ActorWriter(Bytes, false);
	FObjectAndNameAsStringProxyArchive Archive(ActorWriter, true);
	Archive.SetIsLoading(true);
	Archive << *DumpFile;

	for (FString FileToCreate : Files)
	{
		TArray<FAssetDumpEntry> OrderedAssetsToCreate;
		for (FAssetDumpEntry& Entry : DumpFile->Assets)
		{
			if (Entry.PackagePath / Entry.AssetName.ToString() == FileToCreate)
			{
				GetDependencies(OrderedAssetsToCreate, *DumpFile, Entry);
				break;
			}
		}

		CreateAssetDummies(OrderedAssetsToCreate);
	}
}

void ULocAssetDumpImporter::TestDependencies(FString Path, FString File)
{
	TArray<uint8> Bytes;
	FFileHelper::LoadFileToArray(Bytes, *Path);

	TSharedPtr<FAssetDumpFile> DumpFile = MakeShareable(new FAssetDumpFile);
	
	FMemoryReader ActorWriter(Bytes, false);
	FObjectAndNameAsStringProxyArchive Archive(ActorWriter, true);
	Archive.SetIsLoading(true);
	Archive << *DumpFile;

	TArray<FAssetDumpEntry> OrderedAssetsToCreate;
	for (FAssetDumpEntry& Entry : DumpFile->Assets)
	{
		if (Entry.PackagePath / Entry.AssetName.ToString() == File)
		{
			GetDependencies(OrderedAssetsToCreate, *DumpFile, Entry);
			break;
		}
	}

	for (auto ToCreate : OrderedAssetsToCreate)
	{
		UE_LOG(LogTemp, Log, TEXT("%s"), *(ToCreate.PackagePath / ToCreate.AssetName.ToString()));
	}
}

void ULocAssetDumpImporter::OverwriteData(TSharedPtr<FAssetDumpFile> DumpFile, TArray<FAssetData>& Data)
{
	TArray<FAssetDumpEntry> OrderedAssetsToCreate;
	TArray<UObject*> OrderedAssetsToDelete;
	for (FAssetData& AssetData : Data)
	{
		for (FAssetDumpEntry& Entry : DumpFile->Assets)
		{
			if (Entry.PackagePath / Entry.AssetName.ToString() == AssetData.PackagePath.ToString() / AssetData.AssetName.ToString())
			{
				TArray<FAssetDumpEntry> Deps;
				GetDependencies(Deps, *DumpFile, Entry);
				for (auto& Dep : Deps)
				{
					if (!OrderedAssetsToCreate.Contains(Dep))
					{
						OrderedAssetsToCreate.Add(Dep);
					}
					else
					{
						OrderedAssetsToCreate.Remove(Dep);
						OrderedAssetsToCreate.Add(Dep);
					}
				}
				
				OrderedAssetsToDelete.Add(AssetData.GetAsset());
				break;
			}
		}
	}
	
	ObjectTools::ForceDeleteObjects(OrderedAssetsToDelete, false);

	TMap<int, UBlueprint*> Blueprints;
	for (int i = OrderedAssetsToCreate.Num() - 1; i >= 0; i--)
	{
		auto& ToCreate = OrderedAssetsToCreate[i];
		UE_LOG(LogTemp, Log, TEXT("CREATE %s"), *(ToCreate.PackagePath / ToCreate.AssetName.ToString()));
		UObject* Obj = CreateAssetForAssetEntry(ToCreate);
		if (IsValid(Obj))
		{
			UBlueprint* Blueprint = Cast<UBlueprint>(Obj);
			if (IsValid(Blueprint))
			{
				Blueprints.Add(i, Blueprint);
			}
		}
	}

	for (auto Blueprint : Blueprints)
	{
		FinishCreateBlueprintAsset(Blueprint.Value, OrderedAssetsToCreate[Blueprint.Key]);
	}
}

void ULocAssetDumpImporter::OpenAssetDumpImporter(TSharedPtr<FAssetDumpFile> DumpFile)
{
	TSharedPtr<TArray<ReportPackageData>> PackageDatas = MakeShareable(new TArray<ReportPackageData>);
	for (auto& Entry : DumpFile->Assets)
	{
		PackageDatas->Add({Entry, false});
	}
	
	SAssetDumpImporter::FOnReportConfirmed OnReportConfirmed = SAssetDumpImporter::FOnReportConfirmed::CreateLambda([PackageDatas, DumpFile]()
	{
		TArray<FAssetDumpEntry> OrderedAssetsToCreate;
		TArray<FAssetDumpEntry> AssetsPreSelected;
		for (auto PackageDataIt = PackageDatas->CreateConstIterator(); PackageDataIt; ++PackageDataIt)
		{
			if (PackageDataIt->bShouldMigratePackage)
			{
				AssetsPreSelected.Add(PackageDataIt->Entry);
				TArray<FAssetDumpEntry> Deps;
				GetDependencies(Deps, *DumpFile, PackageDataIt->Entry);
				for (auto& Dep : Deps)
				{
					OrderedAssetsToCreate.Remove(Dep);
					OrderedAssetsToCreate.Add(Dep);
				}
			}
		}
		
		FString NewDependencies = "";
		for (auto Package : OrderedAssetsToCreate)
		{
			if (!AssetsPreSelected.Contains(Package))
			{
				NewDependencies += Package.PackagePath / Package.AssetName.ToString() + "\n";
			}
		}

		auto Result = FMessageDialog::Open(EAppMsgCategory::Info, EAppMsgType::OkCancel, FText::FromString(FString::Printf(TEXT("These dependencies will also be added:\n%s"), *NewDependencies)));
		if (Result == EAppReturnType::Ok)
		{
			CreateAssetDummies(OrderedAssetsToCreate);
		}
	});
	SAssetDumpImporter::OpenPackageReportDialog(FText::FromString("Select what to import"), *PackageDatas.Get(), OnReportConfirmed);
}

UObject* ULocAssetDumpImporter::CreateAssetForAssetEntry(const FAssetDumpEntry& Entry)
{
	if (Entry.AssetClassPath.Contains("NiagaraSystem"))
	{
		return nullptr;
	}
	
	IAssetRegistry& AssetRegistry = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();

	FString SoftObjPath = Entry.PackagePath + "/" + Entry.AssetName.ToString() + "." + Entry.AssetName.ToString();
	if (AssetRegistry.GetAssetByObjectPath(FSoftObjectPath(SoftObjPath)) != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("exists %s %s"), *Entry.PackagePath, *Entry.AssetName.ToString());
		return nullptr;
	}
		
	UE_LOG(LogTemp, Log, TEXT("CREATING %s %s"), *Entry.PackagePath, *Entry.AssetName.ToString());
	UObject* NewAsset = nullptr;
	if (Entry.AssetClassPath == "/Script/Engine.StaticMesh")
	{
		UStaticMesh* SourceMesh = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, TEXT("/Engine/BasicShapes/Cube.Cube")));
		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
		NewAsset = AssetTools.DuplicateAsset(Entry.AssetName.ToString(), Entry.PackagePath, SourceMesh);
	}
	if (Entry.AssetClassPath == "/Script/Engine.SoundWave")
	{
		USoundWave* SourceWave = Cast<USoundWave>(StaticLoadObject(USoundWave::StaticClass(), nullptr, TEXT("/Engine/EngineSounds/1kSineTonePing.1kSineTonePing")));
		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
		NewAsset = AssetTools.DuplicateAsset(Entry.AssetName.ToString(), Entry.PackagePath, SourceWave);
	}
	
	if (NewAsset == nullptr)
	{
		NewAsset = CreateAsset(Entry, Entry.AssetName.ToString(), Entry.PackagePath, Entry.AssetClassPath, Entry.TagsAndValues);
	}	

	if (NewAsset)
	{
		UE_LOG(LogTemp, Log, TEXT("Successfully created asset: %s at %s"), *Entry.AssetName.ToString(), *Entry.PackagePath);
		FString PackageFileName = FPackageName::LongPackageNameToFilename(Entry.PackagePath, FString::Printf(TEXT("/%s.uasset"), *Entry.AssetName.ToString()));
		FSavePackageArgs Args;
		Args.TopLevelFlags = EObjectFlags::RF_Public | EObjectFlags::RF_Standalone;
		UPackage::SavePackage(NewAsset->GetPackage(), NewAsset, *PackageFileName, Args);
		
		TArray<FString> PathsToScan;
		PathsToScan.Add(Entry.PackagePath + "/" + Entry.AssetName.ToString()); // Add the package path to be scanned
		AssetRegistry.Get()->ScanPathsSynchronous(PathsToScan, true);
	}

	return NewAsset;
}

void ULocAssetDumpImporter::CreateBlueprintVariables(const FAssetDumpEntry& Entry, UBlueprint* Blueprint)
{
	TArray<FString> VariablesCreated;
	// create variables by hierarchy
	CreateBlueprintVariable(Entry, Entry.DefaultSceneRoot, Blueprint, VariablesCreated);
	// ensure all other variables too
	for (auto& Var : Entry.Variables)
    {
    	CreateBlueprintVariable(Entry, Var, Blueprint, VariablesCreated);
    }
}

void ULocAssetDumpImporter::CreateBlueprintVariable(const FAssetDumpEntry& Entry, const FAssetDumpEntry_Variable& Variable, UBlueprint* Blueprint, TArray<FString>& VariablesCreated)
{
	if (Variable.Name == "UberGraphFrame")
	{
		return;
	}

	if (VariablesCreated.Contains(Variable.Name))
	{
		return;
	}
	
	VariablesCreated.Add(Variable.Name);

	FEdGraphPinType Pin = GetPinTypeForVariable(Variable);
	if (Variable.bIsConstructionScriptVariable)
	{
		UBlueprintGeneratedClass* BPGC = Cast<UBlueprintGeneratedClass>(Blueprint->GeneratedClass);
		if (BPGC)
		{
			FName ComponentName = FName(*Variable.Name);
			Blueprint->Modify();
			USCS_Node* Node = Blueprint->SimpleConstructionScript->CreateNode(Cast<UClass>(Pin.PinSubCategoryObject), ComponentName);
			if (Variable.VariableGuid != FGuid(0, 0, 0, 0))
			{
				Node->VariableGuid = Variable.VariableGuid;
			}
			Blueprint->SimpleConstructionScript->AddNode(Node);
		}
	}
	else
	{
		FBlueprintEditorUtils::AddMemberVariable(Blueprint, FName(Variable.Name), Pin);

		if (Variable.VariableGuid != FGuid(0, 0, 0, 0))
		{
			for (auto& NewVariable : Blueprint->NewVariables)
			{
				if (NewVariable.VarName == FName(Variable.Name))
				{
					NewVariable.VarGuid = Variable.VariableGuid;
					break;
				}
			}
		}
		
		// ✅ Set metadata for ExposeOnSpawn
		if (Variable.bIsExposeOnSpawn)
		{
			FBlueprintEditorUtils::SetBlueprintVariableMetaData(Blueprint, FName(Variable.Name), nullptr, FBlueprintMetadata::MD_ExposeOnSpawn, TEXT("true"));
		}

		// ✅ Set metadata for InstanceEditable
		FBlueprintEditorUtils::SetBlueprintOnlyEditableFlag(Blueprint, FName(Variable.Name), !Variable.bIsInstanceEditable);

		Blueprint->Modify();
		FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(Blueprint);
	}

	for (auto Child : Variable.ChildNodes)
	{
		CreateBlueprintVariableWithName(Entry, Child, Blueprint, VariablesCreated);
	}
}

void ULocAssetDumpImporter::CreateBlueprintVariableWithName(const FAssetDumpEntry& Entry, const FString& Name, UBlueprint* Blueprint, TArray<FString>& VariablesCreated)
{
	for (auto& Var : Entry.Variables)
	{
		if (Var.Name == Name)
		{
			CreateBlueprintVariable(Entry, Var, Blueprint, VariablesCreated);
			break;
		}
	}
}

void ULocAssetDumpImporter::CreateBlueprintEventGraph(UBlueprint* Blueprint, int& EventPosY, const FAssetDumpEntry_Function& Func)
{
	UEdGraph* EventGraph = FindEventGraph(Blueprint);
	if (EventGraph)
	{
		const FScopedTransaction Transaction(TEXT("Add Custom Event"), FText::FromString("Add Custom Event"), Blueprint);
		Blueprint->Modify();
		EventGraph->Modify();

		bool bValidGuid = Func.GraphGuid != FGuid(0, 0, 0, 0);

		if (Func.bIsComponentBoundEvent)
		{
			auto PinComponent = GetPinTypeForVariable(Func.Params[0]);
			UClass* ComponentType = Cast<UClass>(PinComponent.PinSubCategoryObject);

			FObjectProperty* VariableProperty = FindFProperty<FObjectProperty>(Blueprint->SkeletonGeneratedClass, *Func.Params[0].Name);
			FMulticastDelegateProperty* DelegateProperty = FindFProperty<FMulticastDelegateProperty>(ComponentType, FName(Func.Name));
			if ( DelegateProperty != nullptr )
			{
				UEdGraph* TargetGraph = Blueprint->GetLastEditedUberGraph();

				if ( TargetGraph != nullptr )
				{
					// Figure out a decent place to stick the node
					const FVector2D NewNodePos = TargetGraph->GetGoodPlaceForNewNode();

					// Create a new event node
					UK2Node_ComponentBoundEvent* EventNode = FEdGraphSchemaAction_K2NewNode::SpawnNode<UK2Node_ComponentBoundEvent>(
						TargetGraph,
						NewNodePos,
						EK2NewNodeFlags::SelectNewNode,
						[VariableProperty, DelegateProperty](UK2Node_ComponentBoundEvent* NewInstance)
						{
							NewInstance->InitializeComponentBoundEventParams(VariableProperty, DelegateProperty);
						}
					);

					if (bValidGuid)
					{
						EventNode->NodeGuid = Func.GraphGuid;
					}
				}
			}
		}
		else if (Func.bIsBlueprintImplemented)
		{
			UFunction* OverrideFunc = nullptr;
			UClass* const OverrideFuncClass = FBlueprintEditorUtils::GetOverrideFunctionClass(Blueprint, FName(Func.Name), &OverrideFunc);
			if (OverrideFunc != nullptr)
			{
				FName EventName = OverrideFunc->GetFName();

				UK2Node_Event* NewEventNode = FEdGraphSchemaAction_K2NewNode::SpawnNode<UK2Node_Event>(
						EventGraph,
						EventGraph->GetGoodPlaceForNewNode(),
						EK2NewNodeFlags::SelectNewNode,
						[EventName, OverrideFuncClass](UK2Node_Event* NewInstance)
						{
							NewInstance->EventReference.SetExternalMember(EventName, OverrideFuncClass);
							NewInstance->bOverrideFunction = true;
						}
						);

				if (bValidGuid)
				{
					NewEventNode->NodeGuid = Func.GraphGuid;
				}
			}
			else
			{
				// Use UK2Node_Event for BlueprintImplementableEvent
				UK2Node_Event* ImplementedEvent = NewObject<UK2Node_Event>(EventGraph);
				ImplementedEvent->EventReference.SetExternalMember(FName(*Func.Name), Blueprint->GeneratedClass);
				ImplementedEvent->NodePosX = 200; // Adjust position if needed
				ImplementedEvent->NodePosY = EventPosY += 200;

				ImplementedEvent->AllocateDefaultPins();

				if (bValidGuid)
				{
					ImplementedEvent->NodeGuid = Func.GraphGuid;
				}
			
				EventGraph->AddNode(ImplementedEvent, false);
			}
		}
		else
		{
			UK2Node_CustomEvent* CustomEvent = NewObject<UK2Node_CustomEvent>(EventGraph);
			CustomEvent->CustomFunctionName = FName(*Func.Name);
			CustomEvent->NodePosX = 200; // Adjust position if needed
			CustomEvent->NodePosY = EventPosY += 200;

			if (bValidGuid)
			{
				CustomEvent->NodeGuid = Func.GraphGuid;
			}

			CustomEvent->AllocateDefaultPins();

			// Add parameters as pins
			for (const auto& Param : Func.Params)
			{
				FEdGraphPinType PinType = GetPinTypeForVariable(Param);
				CustomEvent->CreateUserDefinedPin(FName(Param.Name), PinType, EGPD_Output);
			}
				
			EventGraph->AddNode(CustomEvent, false);
		}

		FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(Blueprint);
	}
}

void ULocAssetDumpImporter::CreateBlueprintEventDispatcher(UBlueprint* Blueprint, const FAssetDumpEntry_Function& Func)
{
	const FScopedTransaction Transaction(TEXT("Add Event Dispatcher"), FText::FromString("Add Event Dispatcher"), Blueprint);
	Blueprint->Modify();

	// Create a Multicast Delegate variable
	FEdGraphPinType DelegatePinType;
	DelegatePinType.PinCategory = UEdGraphSchema_K2::PC_MCDelegate; // Multicast Delegate type
	FBlueprintEditorUtils::AddMemberVariable(Blueprint, FName(Func.Name), DelegatePinType);

	// Create a unique graph name to avoid collision
	FName EventGraphName = FName(Func.Name);
	UEdGraph* DispatcherGraph = FBlueprintEditorUtils::CreateNewGraph(
		Blueprint,
		EventGraphName,
		UEdGraph::StaticClass(),
		UEdGraphSchema_K2::StaticClass()
	);
	DispatcherGraph->bEditable = false;
			
	const UEdGraphSchema_K2* K2Schema = GetDefault<UEdGraphSchema_K2>();
	K2Schema->CreateDefaultNodesForGraph(*DispatcherGraph);
	K2Schema->CreateFunctionGraphTerminators(*DispatcherGraph, (UClass*)nullptr);
	K2Schema->AddExtraFunctionFlags(DispatcherGraph, (FUNC_BlueprintCallable|FUNC_BlueprintEvent|FUNC_Public));
	K2Schema->MarkFunctionEntryAsEditable(DispatcherGraph, true);
			
	Blueprint->DelegateSignatureGraphs.Add(DispatcherGraph);
			
	UK2Node_FunctionEntry* EntryNode = nullptr;
	for (UEdGraphNode* Node : DispatcherGraph->Nodes)
	{
		EntryNode = Cast<UK2Node_FunctionEntry>(Node);
		if (EntryNode) break;
	}

	// Add parameters to the entry node
	for (const auto& Param : Func.Params)
	{
		FEdGraphPinType PinType = GetPinTypeForVariable(Param);
		EntryNode->CreateUserDefinedPin(FName(Param.Name), PinType, EGPD_Output);
	}
}

void ULocAssetDumpImporter::CreateBlueprintFunction(UBlueprint* Blueprint, const FAssetDumpEntry_Function& Func)
{
	// Create a new function graph
	UEdGraph* NewGraph = FBlueprintEditorUtils::CreateNewGraph(Blueprint, FName(Func.Name), UEdGraph::StaticClass(), UEdGraphSchema_K2::StaticClass());
	UFunction* OverrideFunc = nullptr;
	UClass* const OverrideFuncClass = FBlueprintEditorUtils::GetOverrideFunctionClass(Blueprint, FName(Func.Name), &OverrideFunc);
	FBlueprintEditorUtils::AddFunctionGraph(Blueprint, NewGraph, false, OverrideFuncClass);

	// Create the Function Result Node
	UK2Node_FunctionResult* ReturnNode = NewObject<UK2Node_FunctionResult>(NewGraph);
	ReturnNode->SetFlags(RF_Transactional);
	ReturnNode->NodePosX = 400; // Adjust position for visibility
	ReturnNode->NodePosY = 0;
	ReturnNode->AllocateDefaultPins();
	NewGraph->AddNode(ReturnNode);

	if (OverrideFuncClass == nullptr)
	{
		UK2Node_FunctionEntry* EntryNode = nullptr;
		for (UEdGraphNode* Node : NewGraph->Nodes)
		{
			EntryNode = Cast<UK2Node_FunctionEntry>(Node);
			if (EntryNode) break;
		}
		
		for (auto& Param : Func.Params)
		{
			FEdGraphPinType Pin = GetPinTypeForVariable(Param);
			// input of the function is output of the entry node and the other way for outputs and the return node
			if (Param.bIsInput)
			{
				EntryNode->CreateUserDefinedPin(FName(Param.Name), Pin, EGPD_Output);
			}
			else
			{
				ReturnNode->CreateUserDefinedPin(FName(Param.Name), Pin, EGPD_Input);
			}
		}
	}
}

void ULocAssetDumpImporter::RemoveDefaultNodes(UBlueprint* Blueprint)
{
	auto Nodes = Blueprint->UbergraphPages[0]->Nodes;
	for (int i = Nodes.Num() - 1; i >= 0; i--)
	{
		FBlueprintEditorUtils::RemoveNode(Blueprint, Nodes[i]);
	}
}

UObject* ULocAssetDumpImporter::FinishCreateBlueprintAsset(UBlueprint* Blueprint, const FAssetDumpEntry& Entry)
{
	RemoveDefaultNodes(Blueprint);

	UWidgetBlueprint* WidgetBP = Cast<UWidgetBlueprint>(Blueprint);
	if (IsValid(WidgetBP))
	{
		TSet<UWidget*> ImportedWidgets;
		TMap<FName, UWidgetSlotPair*> PastedExtraSlotData;
		FWidgetBlueprintEditorUtils::ImportWidgetsFromText(WidgetBP, Entry.WidgetTreeText, ImportedWidgets, PastedExtraSlotData);

		for (UWidget* NewWidget : ImportedWidgets)
		{
			if (NewWidget->GetParent() == nullptr)
			{
				WidgetBP->WidgetTree->RootWidget = NewWidget;
				break;
			}
		}

		for (auto Anim : Entry.WidgetAnimations)
		{
			UWidgetAnimation* Animation = NewObject<UWidgetAnimation>(Blueprint, FName(), RF_Transactional);
			Animation->MovieScene = NewObject<UMovieScene>(Animation, FName(Anim.Label));
			Animation->SetDisplayLabel(Anim.Label);
			Animation->Rename(*Anim.Label);

			Animation->MovieScene->SetDisplayRate(FFrameRate(20, 1));
			
			WidgetBP->Animations.Add(Animation);
		}
	}
	
	CreateBlueprintVariables(Entry, Blueprint);

	int EventPosY = 200;
	
	for (auto& Func : Entry.Functions)
	{
		if (Func.bIsEventGraph)
		{
			CreateBlueprintEventGraph(Blueprint, EventPosY, Func);
		}
		else if (Func.bIsEventDispatcher)
		{
			CreateBlueprintEventDispatcher(Blueprint, Func);
		}
		else
		{
			if (Func.Name.StartsWith("ExecuteUber"))
			{
				continue;
			}
			
			CreateBlueprintFunction(Blueprint, Func);
		}
	}

	auto NewVariables = Blueprint->NewVariables;
	Blueprint->NewVariables.Reset();
	for (auto Order : Entry.VariableOrder)
	{
		for (int i = 0; i < NewVariables.Num(); i++)
		{
			if (NewVariables[i].VarName == Order)
			{
				Blueprint->NewVariables.Add(NewVariables[i]);
				NewVariables.RemoveAt(i--);
				break;
			}
		}
	}
	Blueprint->NewVariables.Append(NewVariables);
	
	FKismetEditorUtilities::CompileBlueprint(Blueprint);
	
	return Blueprint;
}

UObject* ULocAssetDumpImporter::CreateBlueprintAsset(UPackage* Package, const FString& UniqueAssetName, const FAssetDumpEntry& Entry,const FString& AssetName, const FString& PackagePath, const FString& AssetClassPath, const TMap<FString, FString>& TagsAndValues)
{
	UBlueprintFactory* BlueprintFactory = NewObject<UBlueprintFactory>();
	UClass* ParentClass = LoadObject<UClass>(nullptr, *TagsAndValues["ParentClass"]);
	if (!IsValid(ParentClass))
	{
		UE_LOG(LogTemp, Warning, TEXT("class %s not found, skipping %s"), *TagsAndValues["ParentClass"], *AssetName);
		return nullptr;
	}
	
	BlueprintFactory->ParentClass = ParentClass;
	UBlueprint* Blueprint = Cast<UBlueprint>(BlueprintFactory->FactoryCreateNew(UBlueprint::StaticClass(), Package, FName(*UniqueAssetName), RF_Public | RF_Standalone, nullptr, GWarn));

	return Blueprint;
}

UObject* ULocAssetDumpImporter::CreateAsset(const FAssetDumpEntry& Entry,const FString& AssetName, const FString& PackagePath, const FString& AssetClassPath, const TMap<FString, FString>& TagsAndValues)
{
	UClass* AssetClass = LoadObject<UClass>(nullptr, *AssetClassPath);
	if (!AssetClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid Asset Class: %s"), *AssetClassPath);
		return nullptr;
	}

	FString PackageName = PackagePath + TEXT("/") + AssetName;
	FString UniquePackageName;
	FString UniqueAssetName;
	FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");
	AssetToolsModule.Get().CreateUniqueAssetName(PackageName, TEXT(""), UniquePackageName, UniqueAssetName);

	UPackage* Package = CreatePackage(*UniquePackageName);
	if (!Package)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to create package: %s"), *UniquePackageName);
		return nullptr;
	}

	UObject* NewAsset = nullptr;
	if (AssetClass == UBlueprint::StaticClass() || AssetClass == UWidgetBlueprint::StaticClass())
	{
		NewAsset = CreateBlueprintAsset(Package, UniqueAssetName, Entry, AssetName, PackagePath, AssetClassPath, TagsAndValues);
	}
	else
	{
		NewAsset = NewObject<UObject>(Package, AssetClass, *UniqueAssetName, RF_Public | RF_Standalone);
	}
	
	if (!NewAsset)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to create asset: %s"), *UniqueAssetName);
		return nullptr;
	}
	
	UNiagaraSystem* NiagaraSystem = Cast<UNiagaraSystem>(NewAsset);
	if (IsValid(NiagaraSystem))
	{
		// Ensure default scripts are assigned to avoid nullptr issues
		NiagaraSystem->SetFlags(RF_Transactional);
		NiagaraSystem->PreEditChange(nullptr);
    
		if (!NiagaraSystem->GetSystemSpawnScript()->GetLatestSource())
		{
			// Create a default empty source if missing
			UNiagaraScriptSource* DefaultSource = NewObject<UNiagaraScriptSource>(NiagaraSystem, UNiagaraScriptSource::StaticClass(), TEXT("DefaultSource"), RF_Transactional);
			FGuid Guid = FGuid::NewGuid();
			NiagaraSystem->GetSystemSpawnScript()->SetSource(DefaultSource, Guid);
			NiagaraSystem->GetSystemUpdateScript()->SetSource(DefaultSource, Guid);
		}

		NiagaraSystem->PostEditChange();
	}
		
	NewAsset->MarkPackageDirty();
	FAssetRegistryModule::AssetCreated(NewAsset);
	Package->SetDirtyFlag(true);

	return NewAsset;
}

FEdGraphPinType ULocAssetDumpImporter::GetPinTypeForVariableType(const FAssetDumpEntry_Variable_Type Var)
{
	FEdGraphPinType VarType;

	// Convert property type to Blueprint-friendly type
	if (Var.Type == FIntProperty::StaticClass()->GetName())
	{
		VarType.PinCategory = UEdGraphSchema_K2::PC_Int;
	}
	else if (Var.Type == FFloatProperty::StaticClass()->GetName())
	{
		VarType.PinCategory = UEdGraphSchema_K2::PC_Real;
		VarType.PinSubCategory = UEdGraphSchema_K2::PC_Float;
	}
	else if (Var.Type == FDoubleProperty::StaticClass()->GetName())
	{
		VarType.PinCategory = UEdGraphSchema_K2::PC_Real;
		VarType.PinSubCategory = UEdGraphSchema_K2::PC_Double;
	}
	else if (Var.Type == FStrProperty::StaticClass()->GetName())
	{
		VarType.PinCategory = UEdGraphSchema_K2::PC_String;
	}
	else if (Var.Type == FBoolProperty::StaticClass()->GetName())
	{
		VarType.PinCategory = UEdGraphSchema_K2::PC_Boolean;
	}
	else if (Var.Type == FObjectProperty::StaticClass()->GetName())
	{
		VarType.PinCategory = UEdGraphSchema_K2::PC_Object;
		VarType.PinSubCategoryObject = LoadClass<UObject>(nullptr, *Var.TargetClass);
	}
	else if (Var.Type == FArrayProperty::StaticClass()->GetName())
	{
		VarType.PinCategory = UEdGraphSchema_K2::PC_Object;
		VarType.ContainerType = EPinContainerType::Array;
	}
	else if (Var.Type == FMapProperty::StaticClass()->GetName())
	{
		VarType.PinCategory = UEdGraphSchema_K2::PC_Object;
		VarType.ContainerType = EPinContainerType::Map;
	}
	else if (Var.Type == FTextProperty::StaticClass()->GetName())
	{
		VarType.PinCategory = UEdGraphSchema_K2::PC_Text;
	}
	else if (Var.Type == FStructProperty::StaticClass()->GetName())
	{
		VarType.PinCategory = UEdGraphSchema_K2::PC_Struct;
		VarType.PinSubCategoryObject = LoadObject<UObject>(nullptr, *Var.TargetClass);
	}
	else if (Var.Type == FEnumProperty::StaticClass()->GetName())
	{
		VarType.PinCategory = UEdGraphSchema_K2::PC_Byte;
		VarType.PinSubCategoryObject = LoadObject<UObject>(nullptr, *Var.TargetClass);
	}
	else if (Var.Type == FSoftObjectProperty::StaticClass()->GetName())
	{
		VarType.PinCategory = UEdGraphSchema_K2::PC_SoftObject;
		VarType.PinSubCategoryObject = LoadObject<UObject>(nullptr, *Var.TargetClass);
	}
	else if (Var.Type == FSoftClassProperty::StaticClass()->GetName())
	{
		VarType.PinCategory = UEdGraphSchema_K2::PC_SoftClass;
		VarType.PinSubCategoryObject = LoadObject<UObject>(nullptr, *Var.TargetClass);
	}
	else if (Var.Type == FClassProperty::StaticClass()->GetName())
	{
		VarType.PinCategory = UEdGraphSchema_K2::PC_Class;
		VarType.PinSubCategoryObject = LoadObject<UObject>(nullptr, *Var.TargetClass);
	}

	return VarType;
}

FEdGraphPinType ULocAssetDumpImporter::GetPinTypeForVariable(const FAssetDumpEntry_Variable Var)
{
	FEdGraphPinType VarType = GetPinTypeForVariableType(Var.Type);

	if (Var.Type.Type == FArrayProperty::StaticClass()->GetName())
	{
		VarType.ContainerType = EPinContainerType::Array;

		// Handle the inner type of the array
		FEdGraphPinType InnerType = GetPinTypeForVariableType(Var.InnerType);
		VarType.PinSubCategoryObject = InnerType.PinSubCategoryObject;

		if (VarType.PinValueType.TerminalCategory != NAME_None)
		{
			VarType.PinCategory = VarType.PinValueType.TerminalCategory;
		}
	}
	else if (Var.Type.Type == FMapProperty::StaticClass()->GetName())
	{
		VarType.ContainerType = EPinContainerType::Map;

		// Handle key type
		FEdGraphPinType KeyType = GetPinTypeForVariableType(Var.InnerType);
		VarType.PinSubCategoryObject = KeyType.PinSubCategoryObject;
		VarType.PinValueType.TerminalCategory = KeyType.PinCategory;
		VarType.PinValueType.TerminalSubCategoryObject = KeyType.PinSubCategoryObject;
		
		VarType.PinCategory = VarType.PinValueType.TerminalCategory;

		// Handle value type
		FEdGraphPinType ValueType = GetPinTypeForVariableType(Var.ValueType);
		VarType.PinValueType.TerminalCategory = ValueType.PinCategory;
		VarType.PinValueType.TerminalSubCategoryObject = ValueType.PinSubCategoryObject;
	}

	return VarType;
}

UEdGraph* ULocAssetDumpImporter::FindEventGraph(UBlueprint* Blueprint)
{
	if (!Blueprint) return nullptr;

	for (UEdGraph* Graph : Blueprint->UbergraphPages)
	{
		if (Graph && Graph->GetFName() == "EventGraph") // Check by name
		{
			return Graph;
		}
	}

	return nullptr; // No EventGraph found
}

void ULocAssetDumpImporter::ListAssetMetaData()
{
	IAssetRegistry& AssetRegistry = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();

	// Ensure the registry is fully loaded
	AssetRegistry.SearchAllAssets(true);

	// Store all asset data
	TArray<FAssetData> AssetDataList;
	AssetRegistry.GetAllAssets(AssetDataList, true);

	// Print asset names
	for (const FAssetData& AssetData : AssetDataList)
	{
		FString ParentClass;
		AssetData.GetTagValue(FName("ParentClass"), ParentClass);
		UE_LOG(LogTemp, Warning, TEXT("Asset: %s %s %s %s %s"),
			*AssetData.AssetName.ToString(),
			*AssetData.AssetClass.ToString(),
			*AssetData.AssetClassPath.ToString(),
			*AssetData.PackagePath.ToString(),
			*ParentClass);
	}
}

bool ULocAssetDumpImporter::GetAssetDumpEntryByLongPackageName(const FAssetDumpFile& DumpFile, const FString& LongPackageName, FAssetDumpEntry& OutEntry)
{
	for (auto& Entry : DumpFile.Assets)
	{
		if (Entry.PackagePath / Entry.AssetName.ToString() == LongPackageName)
		{
			OutEntry = Entry;
			return true;
		}
	}

	return false;
}

void ULocAssetDumpImporter::GetDependencies(TArray<FAssetDumpEntry>& Dependencies, const FAssetDumpFile& DumpFile, const FAssetDumpEntry& TargetEntry)
{
	UE_LOG(LogTemp, Log, TEXT("DEPS %s"), *(TargetEntry.PackagePath / TargetEntry.AssetName.ToString()));
	if (Dependencies.Contains(TargetEntry))
	{
		Dependencies.Remove(TargetEntry);
		Dependencies.Add(TargetEntry);
	}
	else
	{
		Dependencies.Add(TargetEntry);
	}

	TArray<FAssetDumpEntry> NewEntries;
	const FAssetDumpEntryDependency* AssetDumpEntryDependency = DumpFile.Dependencies.Find(TargetEntry.PackagePath / TargetEntry.AssetName.ToString());
	if (AssetDumpEntryDependency != nullptr)
	{
		for (auto Dep : (*AssetDumpEntryDependency).LongPackageNames)
		{
			FAssetDumpEntry Entry;
			if (GetAssetDumpEntryByLongPackageName(DumpFile, Dep, Entry))
			{
				if (Dependencies.Contains(Entry))
				{
					Dependencies.Remove(Entry);
					Dependencies.Add(Entry);
				}
				else
				{
					Dependencies.Add(Entry);
					NewEntries.Add(Entry);
				}
			}
		}
	}

	for (auto Entry : NewEntries)
	{
		GetDependencies(Dependencies, DumpFile, Entry);
	}
	
	UE_LOG(LogTemp, Log, TEXT("END %s"), *(TargetEntry.PackagePath / TargetEntry.AssetName.ToString()));
}
