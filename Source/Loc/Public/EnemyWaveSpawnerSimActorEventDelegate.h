#pragma once
#include "CoreMinimal.h"
#include "EnemyWaveSpawnerSimActorEventDelegate.generated.h"

class ASimulationActor;
class UEnemyWaveSpawnerSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEnemyWaveSpawnerSimActorEvent, UEnemyWaveSpawnerSimulationComponent*, WaveSpawnerComponent, ASimulationActor*, SimActor);

