#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Templates/SubclassOf.h"
#include "BPFL_ActorCondition.generated.h"

class AActor;
class UActorConditionStrategy;

UCLASS(Blueprintable)
class LOC_API UBPFL_ActorCondition : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UBPFL_ActorCondition();

    UFUNCTION(BlueprintCallable)
    static bool IsConditionFulfilled_Branched(const AActor* Actor, TSubclassOf<UActorConditionStrategy> Condition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsConditionFulfilled(const AActor* Actor, TSubclassOf<UActorConditionStrategy> Condition);
    
    UFUNCTION(BlueprintCallable)
    static bool AreAllConditionsFulfilled_Branched(const AActor* Actor, TArray<TSubclassOf<UActorConditionStrategy>> Conditions);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool AreAllConditionsFulfilled(const AActor* Actor, TArray<TSubclassOf<UActorConditionStrategy>> Conditions);
    
};

