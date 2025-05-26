#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ActorConditionStrategy.generated.h"

class AActor;

UCLASS(Abstract, Blueprintable)
class LOC_API UActorConditionStrategy : public UObject {
    GENERATED_BODY()
public:
    UActorConditionStrategy();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsFulfilled(const AActor* Actor) const;
    
};

