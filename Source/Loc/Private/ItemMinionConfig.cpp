#include "ItemMinionConfig.h"
#include "FormationStrategy_Box.h"

UItemMinionConfig::UItemMinionConfig() {
    this->MinionClass = NULL;
    this->ThrowInputContextClass = NULL;
    this->MinionSummaryUIClass = NULL;
    this->FormationStrategy = UFormationStrategy_Box::StaticClass();
    this->bCanBeUsedInWorkstations = true;
    this->OffsetFromWorkbench = 35.00f;
    this->WorkingAnimation = NULL;
    this->IdleAnimation = NULL;
    this->DefenseStarsCount = 0.00f;
    this->CapacityStarsCount = 0.00f;
    this->OffenseStarsCount = 0.00f;
    this->EfficiencyStarsCount = 0.00f;
}

ASimulationActor* UItemMinionConfig::SpawnMinion(ASimulationManager* SimulationManager, FIntVector position, UItemStackData* Data) {
    return NULL;
}


