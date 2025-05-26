#pragma once
#include "CoreMinimal.h"
#include "BossTokenGeneratorSpeedChangedDelegate.generated.h"

class UBossTokenGenerator;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBossTokenGeneratorSpeedChanged, UBossTokenGenerator*, Component, int32, TargetSpeed);

