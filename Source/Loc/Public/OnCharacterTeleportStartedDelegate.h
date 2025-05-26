#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "OnCharacterTeleportStartedDelegate.generated.h"

class ALocCharacter;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnCharacterTeleportStarted, ALocCharacter*, Character, FVector, TargetLocation, FRotator, TargetRotation, bool, bIsInLoadingScreen);

