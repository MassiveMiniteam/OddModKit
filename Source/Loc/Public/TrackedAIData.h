#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TrackedAIData.generated.h"

class UBaseState;

USTRUCT(BlueprintType)
struct FTrackedAIData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UBaseState>, int32> StateToCount;
    
    LOC_API FTrackedAIData();
};

