#pragma once
#include "CoreMinimal.h"
#include "Components/CanvasPanelSlot.h"
#include "ZoomCanvasPanelSlot.generated.h"

UCLASS(Blueprintable)
class LOC_API UZoomCanvasPanelSlot : public UCanvasPanelSlot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreResizeOnZoom;
    
    UZoomCanvasPanelSlot();

};

