#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "EnemySpawnStrategy.h"
#include "EnemyWaveSpawnerStrategy_HostilitySystem.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UEnemyWaveSpawnerStrategy_HostilitySystem : public UEnemySpawnStrategy {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed BaseSpawnInterval;
    
public:
    UEnemyWaveSpawnerStrategy_HostilitySystem();

};

