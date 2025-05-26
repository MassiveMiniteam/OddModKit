#pragma once

#include "CoreMinimal.h"
#include "SGraphNode.h"

class UEdNode_NoiseGraphNode;

class NOISEGRAPHEDITOR_API SEdNode_NoiseGraphNode : public SGraphNode, public FGCObject
{
public:
	SLATE_BEGIN_ARGS(SEdNode_NoiseGraphNode) {}
	SLATE_END_ARGS()

	TObjectPtr<UTexture2D> PreviewTexture;
	FSlateBrush Brush;
	
	void Construct(const FArguments& InArgs, UEdNode_NoiseGraphNode* InNode);

	virtual void CreatePinWidgets() override;
	virtual void AddPin(const TSharedRef<SGraphPin>& PinToAdd) override;
	virtual bool IsNameReadOnly() const override;

	void OnNameTextCommited(const FText& InText, ETextCommit::Type CommitInfo);

	virtual FSlateColor GetBorderBackgroundColor() const;
	virtual FSlateColor GetBackgroundColor() const;

	virtual EVisibility GetDragOverMarkerVisibility() const;

	virtual const FSlateBrush* GetNameIcon() const;

	virtual void UpdateGraphNodeWithSeed(int InSeed, bool bUpdateGraphNode = true);
protected:
	virtual void CreateBelowPinControls(TSharedPtr<SVerticalBox> MainBox) override;
	TSharedRef<SWidget> CreatePreviewWidget();

	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
	virtual FString GetReferencerName() const override
	{
		return TEXT("FAssetEditor_LTNoiseGraphNode");
	}
	UTexture* GetOrInitPreviewTexture();
};

