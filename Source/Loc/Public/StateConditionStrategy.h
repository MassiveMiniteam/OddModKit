#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "StateConditionStrategy.generated.h"

class UBaseState;

UCLASS(Abstract, Blueprintable)
class LOC_API UStateConditionStrategy : public UObject {
    GENERATED_BODY()
public:
    UStateConditionStrategy();

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool OnCheck(const UBaseState* InitializedState) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool Check(const UBaseState* InitializedState) const;
    
};

