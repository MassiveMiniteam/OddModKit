#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "GameplayEffect.h"
#include "Templates/SubclassOf.h"
#include "GameplayAbility.generated.h"

class ASimulationActor;
class UGameplayAbility;
class UGameplayAbilityComponent;
class UGameplayAbilityCondition;
class UGameplayAbilityTargeting;

UCLASS(Abstract, Blueprintable)
class LOC_API UGameplayAbility : public UGameplayEffect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed TimeUntilHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UGameplayEffect>> GameplayEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed Cooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UGameplayAbility>> ConnectedCoolDowns;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UGameplayAbilityCondition>> Conditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed WindupTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag WindupAnimationTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayAbilityTargeting> TargetingClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayAbilityTargeting> TargetingEffectClassOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMoveTowardsTargetActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed StartExecutionMaxRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed StartExecutionMaxAngleDelta;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSnapRotationToTargetOnStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSnapRotationToTargetOnTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag AnimationTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoStartAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed AnimationStopToHitDuration;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UGameplayAbilityComponent> OwnerAbilityComponent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed ElapsedCooldown;
    
public:
    UGameplayAbility();

protected:
    UFUNCTION(BlueprintCallable)
    void StartAbilityAnimation();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTargetHit(ASimulationActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void OnAbilityExecuted_Native(const TArray<ASimulationActor*>& TargetsHit);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAbilityExecuted(const TArray<ASimulationActor*>& TargetsHit);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<ASimulationActor*> GetTargetsByStrategy(TSubclassOf<UGameplayAbilityTargeting> Strategy) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<ASimulationActor*> GetTargets() const;
    
    UFUNCTION(BlueprintCallable)
    void CancelAbility(FFixed LoopDelta);
    
};

