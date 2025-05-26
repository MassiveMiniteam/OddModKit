#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "EnemySpawnStrategy.h"
#include "EnemyWaveSpawnerStrategy_FixedWave.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UEnemyWaveSpawnerStrategy_FixedWave : public UEnemySpawnStrategy {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed SpawnInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Budget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed WaveStartBlockDuration;
    
public:
    UEnemyWaveSpawnerStrategy_FixedWave();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetWaveBlockDuration() const;
    
};

