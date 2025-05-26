#pragma once
#include "CoreMinimal.h"
#include "BiomeMusicPlayerEventDelegate.generated.h"

class UMusicPlayerComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBiomeMusicPlayerEvent, UMusicPlayerComponent*, Component);

