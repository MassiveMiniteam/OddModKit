#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "LocSimulationSubsystem.h"
#include "GlobalHostilityLevelSubsystem.generated.h"

class ASimulationActor;
class UDataTable;
class UStatsComponent;

UCLASS(Blueprintable)
class LOC_API UGlobalHostilityLevelSubsystem : public ULocSimulationSubsystem {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int64 KillCounterHostilityPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<ASimulationActor*> LivingEnemies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* CachedEnemyHostilityIncreaseValuesTable;
    
public:
    UGlobalHostilityLevelSubsystem();

    UFUNCTION(BlueprintCallable)
    void RegisterActorForHostilityIncreaseOnDeath(ASimulationActor* Actor);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnActorDied(UStatsComponent* StatsComponent);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetRelativeLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetNeededKillPointsForLevel(int32 Level);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetMaxLevel();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetKillPoints() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentHostilityLevel() const;
    
    UFUNCTION(BlueprintCallable)
    void AddKillPoints(int32 Amount);
    
};

