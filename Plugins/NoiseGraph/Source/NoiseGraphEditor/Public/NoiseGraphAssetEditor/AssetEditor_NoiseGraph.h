#pragma once

#include "CoreMinimal.h"
#include "AdvancedPreviewScene.h"
#include "Settings_NoiseGraphEditor.h"
#include "NoiseGraph.h"

#if ENGINE_MAJOR_VERSION == 5
#include "UObject/ObjectSaveContext.h"
#endif // #if ENGINE_MAJOR_VERSION == 5

class UProceduralMeshComponent;
class FGGAssetEditorToolbar;

class NOISEGRAPHEDITOR_API FAssetEditor_NoiseGraph : public FAssetEditorToolkit, public FNotifyHook, public FGCObject
{
public:
	FAssetEditor_NoiseGraph();
	virtual ~FAssetEditor_NoiseGraph();

	void InitNoiseGraphAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UNoiseGraph* Graph);

	// IToolkit interface
	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& TabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& TabManager) override;
	// End of IToolkit interface

	// FAssetEditorToolkit
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FText GetToolkitName() const override;
	virtual FText GetToolkitToolTipText() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FString GetDocumentationLink() const override;
	virtual void SaveAsset_Execute() override;
	// End of FAssetEditorToolkit

	//Toolbar
	void UpdateToolbar();
	TSharedPtr<class FAssetEditorToolbar_NoiseGraph> GetToolbarBuilder() { return ToolbarBuilder; }
	void RegisterToolbarTab(const TSharedRef<class FTabManager>& TabManager);


	// FSerializableObject interface
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
	// End of FSerializableObject interface

#if ENGINE_MAJOR_VERSION == 5
	// FGCObject interface
	virtual FString GetReferencerName() const
	{
		return TEXT("FAssetEditor_LTNoiseGraph");
	}
	// ~FGCObject interface
#endif // #if ENGINE_MAJOR_VERSION == 5

	UNoiseGraphEditorSettings* GetSettings() const;

protected:
	TSharedRef<SDockTab> SpawnTab_Viewport(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnTab_Details(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnTab_Preview(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnTab_EditorSettings(const FSpawnTabArgs& Args);

	void CreateInternalWidgets();
	TSharedRef<SGraphEditor> CreateViewportWidget();


	void BindCommands();

	void CreateEdGraph();

	void CreateCommandList();

	UProceduralMeshComponent* ProceduralMeshComponent;
	void UpdatePreview();

	TSharedPtr<SGraphEditor> GetCurrGraphEditor() const;

	FGraphPanelSelectionSet GetSelectedNodes() const;

	void RebuildNoiseGraph();

	// Delegates for graph editor commands
	void SelectAllNodes();
	bool CanSelectAllNodes();
	void DeleteSelectedNodes();
	bool CanDeleteNodes();
	void DeleteSelectedDuplicatableNodes();
	void CutSelectedNodes();
	bool CanCutNodes();
	void CopySelectedNodes();
	bool CanCopyNodes();
	void PasteNodes();
	void PasteNodesHere(const FVector2D& Location);
	bool CanPasteNodes();
	void DuplicateNodes();
	bool CanDuplicateNodes();

	void GraphSettings();
	bool CanGraphSettings() const;

	void GeneratePreviews();
	bool CanGeneratePreviews() const;
	//////////////////////////////////////////////////////////////////////////
	// graph editor event
	void OnSelectedNodesChanged(const TSet<class UObject*>& NewSelection);

	void OnNodeDoubleClicked(UEdGraphNode* Node);

	void OnFinishedChangingProperties(const FPropertyChangedEvent& PropertyChangedEvent);

#if ENGINE_MAJOR_VERSION < 5
	void OnPackageSaved(const FString& PackageFileName, UObject* Outer);
#else // #if ENGINE_MAJOR_VERSION < 5
	void OnPackageSavedWithContext(const FString& PackageFileName, UPackage* Package, FObjectPostSaveContext ObjectSaveContext);
#endif // #else // #if ENGINE_MAJOR_VERSION < 5

protected:
	UNoiseGraphEditorSettings* GenricGraphEditorSettings;

	TObjectPtr<UNoiseGraph> EditingGraph;

	//Toolbar
	TSharedPtr<class FAssetEditorToolbar_NoiseGraph> ToolbarBuilder;

	/** Handle to the registered OnPackageSave delegate */
	FDelegateHandle OnPackageSavedDelegateHandle;

	TSharedPtr<SGraphEditor> ViewportWidget;
	TSharedPtr<class IDetailsView> PropertyWidget;
	TSharedPtr<class IDetailsView> EditorSettingsWidget;
	
	TSharedPtr<FAdvancedPreviewScene> AdvancedPreviewScene;

	FSlateBrush BigPreviewBrush;
	TSharedPtr<SWidget> BigPreviewWidget;
	TSharedPtr<SViewport> PreviewViewportWidget;
	TSharedPtr<FSceneViewport> SceneViewport;
	TSharedPtr<FEditorViewportClient> Client;

	/** The command list for this editor */
	TSharedPtr<FUICommandList> GraphEditorCommands;
};


