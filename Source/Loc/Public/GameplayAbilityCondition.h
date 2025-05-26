#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Templates/SubclassOf.h"
#include "GameplayAbilityCondition.generated.h"

class UGameplayAbility;
class UGameplayAbilityComponent;

UCLASS(Abstract, Blueprintable)
class LOC_API UGameplayAbilityCondition : public UObject {
    GENERATED_BODY()
public:
    UGameplayAbilityCondition();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsFulfilled(const UGameplayAbilityComponent* GameplayAbilityComponent, TSubclassOf<UGameplayAbility> GameplayAbility) const;
    
};

