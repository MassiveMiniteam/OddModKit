#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "EnemyWaveSpawnerEventDelegate.h"
#include "EnemyWaveSpawnerSimActorEventDelegate.h"
#include "SimulationTimerComponent.h"
#include "Templates/SubclassOf.h"
#include "EnemyWaveSpawnerSimulationComponent.generated.h"

class ASimulationActor;
class UEnemySpawnStrategy;
class UGameplayEffect;
class UPositionSimulationComponent;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UEnemyWaveSpawnerSimulationComponent : public USimulationTimerComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnemySpawnStrategy> DefaultStrategy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsAffectedBySpawnBlocker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UEnemySpawnStrategy* ActiveStrategy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<ASimulationActor*> CurrentMonsters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UGameplayEffect>> EffectsToAssignToMonster;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPositionSimulationComponent* CachedPositionComponent;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemyWaveSpawnerEvent OnWaveCompletelySpawned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemyWaveSpawnerSimActorEvent OnNewEnemySpawned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemyWaveSpawnerSimActorEvent OnExternalEnemyAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemyWaveSpawnerEvent OnLastEnemyDied;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemyWaveSpawnerEvent OnSpawnStrategyChanged;
    
    UEnemyWaveSpawnerSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StopWave();
    
    UFUNCTION(BlueprintCallable)
    void StartWaveWithDefaultStrategy();
    
    UFUNCTION(BlueprintCallable)
    void StartWaveWithCustomStrategy(TSubclassOf<UEnemySpawnStrategy> Strategy);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnUnitDied(UStatsComponent* StatsComponent);
    
    UFUNCTION(BlueprintCallable)
    void OnTimerStoppedCallback(USimulationTimerComponent* SimulationTimerComponent);
    
public:
    UFUNCTION(BlueprintCallable)
    void KillAllMonster();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWaveCompletelySpawned() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCurrentlyAffectedBySpawnBlocker();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRemainingBudget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetRelativeRemainingBudget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentTotalBudget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASimulationActor*> GetCurrentMonsters() const;
    
    UFUNCTION(BlueprintCallable)
    void AddExternalMonster(ASimulationActor* InExternalMonster);
    
};

