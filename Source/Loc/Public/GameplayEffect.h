#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "EDestructionReason.h"
#include "EValidityState.h"
#include "Fixed.h"
#include "SerializedSimulationObject.h"
#include "EGameplayEffectStackingPolicy.h"
#include "EGameplayEffectSuccessionPolicy.h"
#include "GameplayStatModifierArray.h"
#include "OnGameplayEffectEndedDelegate.h"
#include "Templates/SubclassOf.h"
#include "GameplayEffect.generated.h"

class AActor;
class ASimulationActor;
class UGameplayEffect;
class UStatsComponent;

UCLASS(Abstract, Blueprintable)
class LOC_API UGameplayEffect : public USerializedSimulationObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldBeVisualizedSequentially;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed LocalDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed TickSpeedFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed Duration;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGameplayEffectEnded OnGameplayEffectEnded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> CachedStatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ASimulationActor> Instigator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsStarted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer PreventApplicationIfAnyTagOnTargetExists;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer RequiredTagsOnTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameplayEffectStackingPolicy StackingPolicy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameplayEffectSuccessionPolicy SuccessionPolicy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 CurrentNumStacks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumMaxStacks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FGameplayStatModifierArray> StatModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ApplicationProbability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UGameplayEffect>> SuccessionEffects;
    
public:
    UGameplayEffect();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Visualize();
    
    UFUNCTION(BlueprintCallable)
    void StopEffectWithReason(EDestructionReason Reason);
    
    UFUNCTION(BlueprintCallable)
    void StopEffect();
    
    UFUNCTION(BlueprintCallable)
    void SetInstigator(ASimulationActor* InstigatorIn);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTickEffect(FFixed DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    void OnStopEffectWithReason_Native(EDestructionReason Reason);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStopEffectWithReason(EDestructionReason Reason);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStopEffect();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartEffect(bool bIsLoading);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStackAmountChanged(int32 OldAmount, int32 NewAmount);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSimulationActorShutDown(ASimulationActor* SimulationActor, EDestructionReason Reason);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDurationReached();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInstantEffect() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInSpecificTimeWindow(FFixed TimeWindowStart, FFixed TimeWindowEnd) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInSpecificFrameTime(FFixed Time, FFixed DeltaTime) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInfiniteEffect() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EGameplayEffectStackingPolicy GetStackingPolicy() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetRelativeStackAmount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    AActor* GetPresentationActor(EValidityState& ValidityState) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    int32 GetNumMaxStacks(UStatsComponent* TargetStats) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumCurrentStacks() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<FGameplayTag, FGameplayStatModifierArray> GetModifiers() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASimulationActor* GetInstigator();
    
    UFUNCTION(BlueprintCallable)
    void ChangeNumStacks(int32 NewNumStacks);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanApplyEffect(UStatsComponent* StatsComponent);
    
};

