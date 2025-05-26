#pragma once
#include "CoreMinimal.h"
#include "EnemyWaveSpawnerEventDelegate.generated.h"

class UEnemyWaveSpawnerSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnemyWaveSpawnerEvent, UEnemyWaveSpawnerSimulationComponent*, WaveSpawnerComponent);

