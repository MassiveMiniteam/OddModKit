#pragma once
#include "CoreMinimal.h"
#include "SeedPreviewGeneratedEventDelegate.generated.h"

class USeedPreviewWidget;
class UTexture2D;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSeedPreviewGeneratedEvent, USeedPreviewWidget*, Widget, UTexture2D*, GeneratedTexture);

