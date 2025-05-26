#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayEffect.h"
#include "GameplayEffectIncreaseStatForDuration.generated.h"

UCLASS(Blueprintable)
class LOC_API UGameplayEffectIncreaseStatForDuration : public UGameplayEffect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGameplayTag Tag;
    
    UGameplayEffectIncreaseStatForDuration();

};

