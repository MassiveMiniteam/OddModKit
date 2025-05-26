#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "EAbilityStatus.h"
#include "Templates/SubclassOf.h"
#include "GameplayAbilityComponent.generated.h"

class ASimulationActor;
class UDifficultySettingsSubsystem;
class UGameplayAbility;
class UPositionSimulationComponent;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGameplayAbilityComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayAbility> DefaultAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UGameplayAbility>> PrioritizedAbilityClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayAbility> RestoreAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UGameplayAbility* ActiveAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatsComponent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> PositionSimulationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayAbility> NextAbilityClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UGameplayAbility*> AbilitiesOnCooldown;
    
public:
    UGameplayAbilityComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StartNextAbility();
    
    UFUNCTION(BlueprintCallable)
    void StartAbility_Internal(TSubclassOf<UGameplayAbility> AbilityClass);
    
    UFUNCTION(BlueprintCallable)
    void SetNextAbilityByPriorities();
    
    UFUNCTION(BlueprintCallable)
    void SetNextAbility(TSubclassOf<UGameplayAbility> AbilityClass);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnDifficultySettingsChanged(UDifficultySettingsSubsystem* Subsystem);
    
    UFUNCTION(BlueprintCallable)
    void OnActiveAbilityFinished();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UGameplayAbility> GetNextAbility() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASimulationActor* GetCurrentTargetActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EAbilityStatus GetCurrentAbilityStatus() const;
    
    UFUNCTION(BlueprintCallable)
    void ClearNextAbility();
    
    UFUNCTION(BlueprintCallable)
    void CancelActiveAbility();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreAllAbilityConditionsFulfilled(TSubclassOf<UGameplayAbility> AbilityClass) const;
    
};

