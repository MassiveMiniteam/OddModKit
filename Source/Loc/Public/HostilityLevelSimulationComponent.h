#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "EvolutionBudget.h"
#include "HostilityLevelChangeEventDelegate.h"
#include "HostilityLevelSimulationComponent.generated.h"

class ASimulationActor;
class UDataTable;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UHostilityLevelSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* EvolutionBudgetTable;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int64 KillCounterHostilityPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<ASimulationActor*> LivingEnemies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* CachedEnemyHostilityIncreaseValuesTable;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHostilityLevelChangeEvent OnHostilityLevelChanged;
    
    UHostilityLevelSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetKillPoints(int32 Points);
    
    UFUNCTION(BlueprintCallable)
    void RegisterActorForHostilityIncreaseOnDeath(ASimulationActor* Actor);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnActorDied(UStatsComponent* StatsComponent);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMaxLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetLevelForPoints(int32 KillPoints) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetKillPoints() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetHostilityIncreaseValue(TSoftClassPtr<ASimulationActor> EnemyClass) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FEvolutionBudget GetEvolutionBudgetForLevel(int32 Level, bool& bSuccess) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FEvolutionBudget GetCurrentEvolutionData() const;
    
    UFUNCTION(BlueprintCallable)
    void AddKillPoints(int32 Amount);
    
};

