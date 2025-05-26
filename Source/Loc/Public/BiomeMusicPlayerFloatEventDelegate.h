#pragma once
#include "CoreMinimal.h"
#include "BiomeMusicPlayerFloatEventDelegate.generated.h"

class UMusicPlayerComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBiomeMusicPlayerFloatEvent, UMusicPlayerComponent*, Component, float, Value);

