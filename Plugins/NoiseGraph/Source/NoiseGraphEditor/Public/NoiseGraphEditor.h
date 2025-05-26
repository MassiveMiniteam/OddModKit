#pragma once
#include "Modules/ModuleManager.h"
#include "NoiseGraphEditorModule.h"
#include <IAssetTools.h>
#include <EdGraphUtilities.h>

class FNoiseGraphEditor : public INoiseGraphEditor
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;


private:
	void RegisterAssetTypeAction(IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action);

private:
	TArray< TSharedPtr<IAssetTypeActions> > CreatedAssetTypeActions;

	EAssetTypeCategories::Type NoiseGraphAssetCategoryBit;

	TSharedPtr<FGraphPanelNodeFactory> GraphPanelNodeFactory_NoiseGraph;
};