#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EnemyWaveSpawnerTableData.generated.h"

class ASimulationActor;

USTRUCT(BlueprintType)
struct FEnemyWaveSpawnerTableData : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ASimulationActor> EnemyClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Cost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpawnProbabilityWeight;
    
    LOC_API FEnemyWaveSpawnerTableData();
};

