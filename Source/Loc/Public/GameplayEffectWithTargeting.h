#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "GameplayEffect.h"
#include "Templates/SubclassOf.h"
#include "GameplayEffectWithTargeting.generated.h"

class ASimulationActor;
class UGameplayAbilityTargeting;

UCLASS(Blueprintable)
class LOC_API UGameplayEffectWithTargeting : public UGameplayEffect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayAbilityTargeting> Targeting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed HitTime;
    
    UGameplayEffectWithTargeting();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ApplyEffect(ASimulationActor* Actor);
    
};

