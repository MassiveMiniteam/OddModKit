#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/PanelWidget.h"
#include "ZoomCanvasPanelValueChangeEventDelegate.h"
#include "ZoomCanvasPanel.generated.h"

class UWidget;
class UZoomCanvasPanelSlot;

UCLASS(Blueprintable)
class LOC_API UZoomCanvasPanel : public UPanelWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FZoomCanvasPanelValueChangeEvent OnZoomLevelChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> AvailableZoomLevels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D DefaultPanelDimension;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ZoomIndex;
    
    UZoomCanvasPanel();

    UFUNCTION(BlueprintCallable)
    void ZoomOut();
    
    UFUNCTION(BlueprintCallable)
    void ZoomIn();
    
    UFUNCTION(BlueprintCallable)
    void SetZoomLevel(int32 InZoomLevelIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetCurrentDimensions() const;
    
    UFUNCTION(BlueprintCallable)
    UZoomCanvasPanelSlot* AddChildToZoomCanvas(UWidget* Content, bool bIgnoreResizeOnZoomLevelChange);
    
};

