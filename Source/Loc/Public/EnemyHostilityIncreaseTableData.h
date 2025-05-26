#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EnemyHostilityIncreaseTableData.generated.h"

class ASimulationActor;

USTRUCT(BlueprintType)
struct FEnemyHostilityIncreaseTableData : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ASimulationActor> EnemyClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HostilityIncreaseValue;
    
    LOC_API FEnemyHostilityIncreaseTableData();
};

