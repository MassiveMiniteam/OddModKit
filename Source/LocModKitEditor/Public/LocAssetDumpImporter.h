// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "LocAssetDumpImporter.generated.h"

struct ReportPackageData;


USTRUCT()
struct FAssetDumpEntry_Variable_Type
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Type;
	
	UPROPERTY()
	FString TargetClass;
	
	friend FArchive& operator<<(FArchive& Ar, FAssetDumpEntry_Variable_Type& MyStruct)
	{
		Ar << MyStruct.Type;
		Ar << MyStruct.TargetClass;
		return Ar;
	}
};

USTRUCT()
struct FAssetDumpEntry_Variable
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Name;
	
	UPROPERTY()
	TArray<FString> ChildNodes;
	
	UPROPERTY()
	FAssetDumpEntry_Variable_Type Type;
	
	UPROPERTY()
	FAssetDumpEntry_Variable_Type InnerType;
	
	UPROPERTY()
	FAssetDumpEntry_Variable_Type ValueType;
	
	UPROPERTY()
	bool bIsInput = true;
	
	UPROPERTY()
	bool bIsConstructionScriptVariable = false;
	
	UPROPERTY()
	bool bIsExposeOnSpawn = false;
	
	UPROPERTY()
	bool bIsInstanceEditable = false;
	
	UPROPERTY()
	FGuid VariableGuid;

	friend FArchive& operator<<(FArchive& Ar, FAssetDumpEntry_Variable& MyStruct)
	{
		Ar << MyStruct.Name;
		Ar << MyStruct.ChildNodes;
		Ar << MyStruct.Type;
		Ar << MyStruct.InnerType;
		Ar << MyStruct.ValueType;
		Ar << MyStruct.bIsInput;
		Ar << MyStruct.bIsConstructionScriptVariable;
		Ar << MyStruct.bIsExposeOnSpawn;
		Ar << MyStruct.bIsInstanceEditable;
		Ar << MyStruct.VariableGuid;
		return Ar;
	}
};

USTRUCT()
struct FAssetDumpEntry_Function
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Name;
	
	UPROPERTY()
	FGuid GraphGuid;

	UPROPERTY()
	bool bIsEventGraph = false; 

	UPROPERTY()
	bool bIsBlueprintImplemented = false; 

	UPROPERTY()
	bool bIsComponentBoundEvent = false; 

	UPROPERTY()
	bool bIsEventDispatcher = false;
	
	UPROPERTY()
	TArray<FAssetDumpEntry_Variable> Params;
	
	friend FArchive& operator<<(FArchive& Ar, FAssetDumpEntry_Function& MyStruct)
	{
		Ar << MyStruct.Name;
		Ar << MyStruct.GraphGuid;
		Ar << MyStruct.Params;
		Ar << MyStruct.bIsEventGraph;
		Ar << MyStruct.bIsBlueprintImplemented;
		Ar << MyStruct.bIsComponentBoundEvent;
		Ar << MyStruct.bIsEventDispatcher;
		return Ar;
	}
};



USTRUCT()
struct FAssetDumpEntryAnimation
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Label;
	
	UPROPERTY()
	FGuid Guid;
	
	friend FArchive& operator<<(FArchive& Ar, FAssetDumpEntryAnimation& MyStruct)
	{
		Ar << MyStruct.Label;
		Ar << MyStruct.Guid;
		return Ar;
	}
};

USTRUCT()
struct FAssetDumpEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName AssetName;
	
	UPROPERTY()
	FString AssetClassPath;
	
	UPROPERTY()
	FString PackagePath;
	
	UPROPERTY()
	TMap<FString, FString> TagsAndValues;
	
	UPROPERTY()
	FAssetDumpEntry_Variable DefaultSceneRoot;
	
	UPROPERTY()
	TArray<FAssetDumpEntry_Variable> Variables;
	
	UPROPERTY()
	TArray<FAssetDumpEntry_Function> Functions;

	UPROPERTY()
	FString WidgetTreeText;

	UPROPERTY()
	TArray<FAssetDumpEntryAnimation> WidgetAnimations;

	UPROPERTY()
	TArray<FName> VariableOrder;
	
	friend FArchive& operator<<(FArchive& Ar, FAssetDumpEntry& MyStruct)
	{
		Ar << MyStruct.AssetName;
		Ar << MyStruct.AssetClassPath;
		Ar << MyStruct.PackagePath;
		Ar << MyStruct.TagsAndValues;
		Ar << MyStruct.DefaultSceneRoot;
		Ar << MyStruct.Variables;
		Ar << MyStruct.Functions;
		Ar << MyStruct.WidgetTreeText;
		Ar << MyStruct.WidgetAnimations;
		Ar << MyStruct.VariableOrder;
		return Ar;
	}
	
	bool operator==(const FAssetDumpEntry& Other) const
	{
		return AssetName == Other.AssetName && PackagePath == Other.PackagePath;
	}
};

USTRUCT()
struct FAssetDumpEntryDependency
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FString> LongPackageNames;
	
	friend FArchive& operator<<(FArchive& Ar, FAssetDumpEntryDependency& MyStruct)
	{
		Ar << MyStruct.LongPackageNames;
		return Ar;
	}
};

USTRUCT()
struct FAssetDumpFile
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FAssetDumpEntry> Assets;
	
	UPROPERTY()
	TMap<FString, FAssetDumpEntryDependency> Dependencies;
	
	friend FArchive& operator<<(FArchive& Ar, FAssetDumpFile& MyStruct)
	{
		Ar << MyStruct.Assets;
		Ar << MyStruct.Dependencies;
		return Ar;
	}
};

/**
 * 
 */
UCLASS(BlueprintType)
class LOCMODKITEDITOR_API ULocAssetDumpImporter : public UObject
{
	GENERATED_BODY()

public:

	static void ImportAssetDump(FString Path, TArray<FAssetData> InDataToOverwrite);
	static void ImportAssetDumpWithFileList(FString Path, TArray<FString> Files);
	static void TestDependencies(FString Path, FString File);
	static void CreateAssetDummies(TArray<FAssetDumpEntry>& OrderedAssetsToCreate);
	static void OverwriteData(TSharedPtr<FAssetDumpFile> DumpFile, TArray<FAssetData>& Data);
	static void OpenAssetDumpImporter(TSharedPtr<FAssetDumpFile> DumpFile);
	static UObject* CreateAssetForAssetEntry(const FAssetDumpEntry& Entry);
	static void CreateBlueprintVariables(const FAssetDumpEntry& Entry, UBlueprint* Blueprint);
	static void CreateBlueprintVariable(const FAssetDumpEntry& Entry, const FAssetDumpEntry_Variable& Variable, UBlueprint* Blueprint, TArray<FString>& VariablesCreated);
	static void CreateBlueprintVariableWithName(const FAssetDumpEntry& Entry, const FString& Name, UBlueprint* Blueprint, TArray<FString>& VariablesCreated);
	static void CreateBlueprintEventGraph(UBlueprint* Blueprint, int& EventPosY, const FAssetDumpEntry_Function& Func);
	static void CreateBlueprintEventDispatcher(UBlueprint* Blueprint, const FAssetDumpEntry_Function& Func);
	static void CreateBlueprintFunction(UBlueprint* Blueprint, const FAssetDumpEntry_Function& Func);
	static void RemoveDefaultNodes(UBlueprint* Blueprint);
	static UObject* FinishCreateBlueprintAsset(UBlueprint* Blueprint, const FAssetDumpEntry& Entry);
	static void ListAssetMetaData();
	static bool GetAssetDumpEntryByLongPackageName(const FAssetDumpFile& DumpFile, const FString& LongPackageName, FAssetDumpEntry& OutEntry);
	static void GetDependencies(TArray<FAssetDumpEntry>& Dependencies, const FAssetDumpFile& DumpFile, const FAssetDumpEntry& TargetEntry);
	static UObject* CreateAsset(const FAssetDumpEntry& Entry, const FString& AssetName, const FString& PackagePath, const FString& AssetClassPath, const TMap<FString, FString>& TagsAndValues);
	static FEdGraphPinType GetPinTypeForVariableType(FAssetDumpEntry_Variable_Type Var);
	static FEdGraphPinType GetPinTypeForVariable(FAssetDumpEntry_Variable Var);
	static UEdGraph* FindEventGraph(UBlueprint* Blueprint);
	static UObject* CreateBlueprintAsset(UPackage* Package, const FString& UniqueAssetName, const FAssetDumpEntry& Entry,const FString& AssetName, const FString& PackagePath, const FString& AssetClassPath, const TMap<FString, FString>& TagsAndValues);
};