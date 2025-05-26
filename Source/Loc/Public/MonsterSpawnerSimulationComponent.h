#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EDestructionReason.h"
#include "Fixed.h"
#include "OnMonsterSpawnedDelegate.h"
#include "SimulationTimerComponent.h"
#include "MonsterSpawnerSimulationComponent.generated.h"

class ASimulationActor;
class UDifficultySettingsSubsystem;
class UStatsComponent;
class UUnitGroupMemberSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UMonsterSpawnerSimulationComponent : public USimulationTimerComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMonsterSpawned OnMonsterSpawned;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ASimulationActor> EnemyClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableSpawnWhenBuildingNearby;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCountSpawnedEnemiesTowardsHostilitySystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed SpawnInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InitialMonsterCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxMonsterCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntVector SpawnPositionOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PlayerSpawnBlockRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpawnRandomRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SpawnWithRandomRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnedMonstersFormUnitGroup;
    
private:
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<ASimulationActor>> Monsters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 MonstersLastFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UUnitGroupMemberSimulationComponent> GroupMemberComponent;
    
public:
    UMonsterSpawnerSimulationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnTimerFired(USimulationTimerComponent* TimerComponent);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnMonsterStatDead(UStatsComponent* StatsComponent);
    
    UFUNCTION(BlueprintCallable)
    void OnMonsterShutdown(ASimulationActor* InSimulationActor, EDestructionReason Reason);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnDifficultySettingsChanged(UDifficultySettingsSubsystem* Subsystem);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASimulationActor*> GetReferencesMonsters() const;
    
};

