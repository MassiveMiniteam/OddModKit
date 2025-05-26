#include "BPFL_EnemyWaveData.h"

UBPFL_EnemyWaveData::UBPFL_EnemyWaveData() {
}

bool UBPFL_EnemyWaveData::TableContainsEnemyThatIsAffordable(const UDataTable* Table, int32 Budget) {
    return false;
}

TSoftClassPtr<ASimulationActor> UBPFL_EnemyWaveData::GetRandomEnemyClassFromTable(const UObject* WorldContext, const UDataTable* Table, int32 Budget) {
    return NULL;
}

int32 UBPFL_EnemyWaveData::GetCostForEnemyInTable(const UDataTable* Table, TSoftClassPtr<ASimulationActor> Class) {
    return 0;
}

int32 UBPFL_EnemyWaveData::CalcRemainingBudgetIncludingCurrentlySpawnedEnemies(const TArray<ASimulationActor*>& LivingEnemies, const UDataTable* Table, int32 TotalBudget) {
    return 0;
}


