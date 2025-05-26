#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "StateMachineStateWithAdditionalConditions.generated.h"

class UBaseState;
class UStateConditionStrategy;

USTRUCT(BlueprintType)
struct FStateMachineStateWithAdditionalConditions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UBaseState> State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UStateConditionStrategy>> EnterConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UStateConditionStrategy>> CancelConditions;
    
    LOC_API FStateMachineStateWithAdditionalConditions();
};

