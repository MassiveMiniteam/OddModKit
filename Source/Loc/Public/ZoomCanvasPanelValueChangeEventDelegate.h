#pragma once
#include "CoreMinimal.h"
#include "ZoomCanvasPanelValueChangeEventDelegate.generated.h"

class UZoomCanvasPanel;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FZoomCanvasPanelValueChangeEvent, UZoomCanvasPanel*, ZoomCanvasPanel, int32, OldZoomIndex, int32, NewZoomIndex);

