#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "BossTokenGeneratorProcessRateChangedDelegate.generated.h"

class UBossTokenGenerator;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBossTokenGeneratorProcessRateChanged, UBossTokenGenerator*, Component, FFixed, ProcessRate);

