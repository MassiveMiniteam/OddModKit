#include "EnemyWaveSpawnerStrategy_FixedWave.h"

UEnemyWaveSpawnerStrategy_FixedWave::UEnemyWaveSpawnerStrategy_FixedWave() {
    this->Budget = 100;
}

FFixed UEnemyWaveSpawnerStrategy_FixedWave::GetWaveBlockDuration() const {
    return FFixed{};
}


