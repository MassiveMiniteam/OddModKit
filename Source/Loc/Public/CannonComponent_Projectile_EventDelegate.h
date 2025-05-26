#pragma once
#include "CoreMinimal.h"
#include "CannonComponent_Projectile_EventDelegate.generated.h"

class UCannonSimulationComponent;
class UProjectileSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCannonComponent_Projectile_Event, UCannonSimulationComponent*, CannonComponent, UProjectileSimulationComponent*, ProjectileSimulationComponent);

