#pragma once
#include "CoreMinimal.h"
#include "ProjectileParameters.h"
#include "ProjectileEventDelegate.generated.h"

class UProjectileSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FProjectileEvent, UProjectileSimulationComponent*, ProjectileSimulationComponent, const FProjectileParameters&, Parameters);

