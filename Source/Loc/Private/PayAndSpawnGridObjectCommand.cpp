#include "PayAndSpawnGridObjectCommand.h"

UPayAndSpawnGridObjectCommand::UPayAndSpawnGridObjectCommand() {
    this->PlayerInventory = NULL;
    this->SimulationActorClass = NULL;
    this->Rotation = 0;
    this->ConstructableConfig = NULL;
    this->RecipeConfig = NULL;
    this->IgnoredGridObject = NULL;
    this->PreviousBuiltGridObject = NULL;
    this->ExecutingSimulationPlayer = NULL;
    this->PredictedGridObject = NULL;
}

void UPayAndSpawnGridObjectCommand::OnPostSpawn_Implementation(AGridObject* SpawnedGridObject) {
}


