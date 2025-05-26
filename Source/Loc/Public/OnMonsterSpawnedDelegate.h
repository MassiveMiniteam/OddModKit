#pragma once
#include "CoreMinimal.h"
#include "OnMonsterSpawnedDelegate.generated.h"

class ASimulationActor;
class UMonsterSpawnerSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMonsterSpawned, UMonsterSpawnerSimulationComponent*, MonsterSpawnerSimulationComponent, ASimulationActor*, Monster);

