#pragma once
#include "CoreMinimal.h"
#include "ItemTrackingData_SingleSnapshot.generated.h"

USTRUCT(BlueprintType)
struct FItemTrackingData_SingleSnapshot {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int64 TotalCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ProductionThisSnapShot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ConsumptionThisSnapShot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ProducedAmountInLastMinute;
    
    LOC_API FItemTrackingData_SingleSnapshot();
};

