#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFL_EnemyWaveData.generated.h"

class ASimulationActor;
class UDataTable;
class UObject;

UCLASS(Blueprintable)
class LOC_API UBPFL_EnemyWaveData : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UBPFL_EnemyWaveData();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool TableContainsEnemyThatIsAffordable(const UDataTable* Table, int32 Budget);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static TSoftClassPtr<ASimulationActor> GetRandomEnemyClassFromTable(const UObject* WorldContext, const UDataTable* Table, int32 Budget);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetCostForEnemyInTable(const UDataTable* Table, TSoftClassPtr<ASimulationActor> Class);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 CalcRemainingBudgetIncludingCurrentlySpawnedEnemies(const TArray<ASimulationActor*>& LivingEnemies, const UDataTable* Table, int32 TotalBudget);
    
};

