#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "EvolutionBudget.generated.h"

USTRUCT(BlueprintType)
struct FEvolutionBudget : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NeededKillPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AvailableBudget;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FInt32Interval RetargetingTimerRandomInterval;
    
    LOC_API FEvolutionBudget();
};

