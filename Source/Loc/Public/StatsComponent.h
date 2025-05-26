#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "EGameplayStatBoolState.h"
#include "GameplayFixedStatMap.h"
#include "GameplayStatChangedEventDelegate.h"
#include "GameplayStatModifier.h"
#include "GameplayStatModifierArray.h"
#include "OnGameplayStatDecreasedDelegate.h"
#include "OnGameplayStatIncreasedDelegate.h"
#include "SimpleStatsCompEventDelegate.h"
#include "TagOnlyEventDelegate.h"
#include "Templates/SubclassOf.h"
#include "StatsComponent.generated.h"

class ASimulationActor;
class UGameplayEffect;
class UGameplayStatsContainer;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UStatsComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKeepTicking;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameplayStatsContainer* StatsContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FGameplayStatModifierArray> ActiveModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UGameplayEffect*> CurrentGameplayEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UGameplayEffect>> InitialEffects;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayStatChangedEvent OnGameplayStatChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGameplayStatIncreased OnGameplayStatIncreased;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGameplayStatDecreased OnGameplayStatDecreased;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTagOnlyEvent OnGameplayStatBoolAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTagOnlyEvent OnGameplayStatBoolRemoved;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimpleStatsCompEvent OnDeadStateTriggered;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimpleStatsCompEvent OnGameplayEffectListChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGameplayFixedStatMap RuntimeStats;
    
    UStatsComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetStatBool(FGameplayTag Tag, bool Value);
    
    UFUNCTION(BlueprintCallable)
    void SetStat(FGameplayTag Tag, FFixed Value);
    
    UFUNCTION(BlueprintCallable)
    void RemoveStatModifiersScaled(FGameplayTag Tag, const TArray<FGameplayStatModifier>& Modifiers, FFixed Scale);
    
    UFUNCTION(BlueprintCallable)
    void RemoveStatModifiersByTag(FGameplayTag StatTag, FGameplayTag ModifierTag);
    
    UFUNCTION(BlueprintCallable)
    void RemoveStatModifiers(FGameplayTag Tag, const TArray<FGameplayStatModifier>& Modifiers);
    
    UFUNCTION(BlueprintCallable)
    void RemoveStatModifier(FGameplayTag Tag, const FGameplayStatModifier& Modifier);
    
    UFUNCTION(BlueprintCallable)
    void RemoveSingleGameplayEffectByType(TSubclassOf<UGameplayEffect> GameplayEffectType);
    
    UFUNCTION(BlueprintCallable)
    void RemoveGameplayEffect(UGameplayEffect* GameplayEffect);
    
    UFUNCTION(BlueprintCallable)
    void RemoveAllGameplayEffects();
    
    UFUNCTION(BlueprintCallable)
    bool IsAnyStatBoolTrue(FGameplayTagContainer Tags);
    
    UFUNCTION(BlueprintCallable)
    int32 IncrementStatValue(FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasTag(FGameplayTag Tag) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAnyTag(FGameplayTagContainer Tags) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAllTags(FGameplayTagContainer Tags) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetStatValue(FGameplayTag Tag) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetStatBoolSimple(FGameplayTag Tag) const;
    
    UFUNCTION(BlueprintCallable)
    void GetStatBool(FGameplayTag Tag, EGameplayStatBoolState& OutStatBoolState);
    
    UFUNCTION(BlueprintCallable)
    bool GetHasTickingGameplayEffect() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UGameplayEffect* FindActiveGameplayEffect(TSubclassOf<UGameplayEffect> GameplayEffectType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ContainsGameplayEffect(TSubclassOf<UGameplayEffect> GameplayEffectType);
    
    UFUNCTION(BlueprintCallable)
    bool AreAllStatBoolsTrue(FGameplayTagContainer Tags);
    
    UFUNCTION(BlueprintCallable)
    void ApplyInitialEffects();
    
    UFUNCTION(BlueprintCallable)
    UGameplayEffect* ApplyGameplayEffectClass(TSubclassOf<UGameplayEffect> GameplayEffectClass, bool bIgnoreApplicationChecks, ASimulationActor* InstigatorIn);
    
    UFUNCTION(BlueprintCallable)
    bool ApplyGameplayEffect(UGameplayEffect* GameplayEffect, bool bIgnoreApplicationChecks);
    
    UFUNCTION(BlueprintCallable)
    void AddToStat(FGameplayTag Tag, FFixed Value, FFixed& OutStatValue);
    
    UFUNCTION(BlueprintCallable)
    void AddStatModifiersScaled(FGameplayTag Tag, const TArray<FGameplayStatModifier>& Modifiers, FFixed Scale);
    
    UFUNCTION(BlueprintCallable)
    void AddStatModifiers(FGameplayTag Tag, const TArray<FGameplayStatModifier>& Modifiers);
    
    UFUNCTION(BlueprintCallable)
    void AddStatModifier(FGameplayTag Tag, const FGameplayStatModifier& Modifier);
    
};

