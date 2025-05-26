#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "GameplayEffectClassAndConditions.h"
#include "GettingAttacked_DelegateDelegate.h"
#include "GettingAttackedSimulationComponent.generated.h"

class ASimulationActor;
class UGameplayAbility;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGettingAttackedSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGettingAttacked_Delegate OnAttackHit;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameplayEffectClassAndConditions> EffectsReflectedToInstigator;
    
public:
    UGettingAttackedSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void AttackHit(ASimulationActor* Instigator, UGameplayAbility* Ability, bool bSuccess);
    
};

