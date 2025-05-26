#include "LocDeveloperSettings.h"

ULocDeveloperSettings::ULocDeveloperSettings() {
    this->DefaultTraceObjectTypes.AddDefaulted(2);
    this->MaxDistanceToIncubatorForAdditionalInputs = 400;
    this->Patching_DontDeleteClassesFromVillage.AddDefaulted(17);
    this->Patching_DeleteClassesFromVillage_Prio.AddDefaulted(2);
    this->Patching_ClassesDontCopyFromNewVillage.AddDefaulted(10);
    this->Patching_UnlockingBehaviours.AddDefaulted(8);
    this->Patching_BiomeCellsThatSpawnedNoEnemiesBug.AddDefaulted(6);
    this->Patching_SpawnIfNotInGameplayMap.AddDefaulted(3);
    this->FlatSeedCellsExceptions.AddDefaulted(1);
    this->FlatSeedCellGameplayTagExceptions.AddDefaulted(2);
    this->FlatSeedBiomeExceptions.AddDefaulted(2);
    this->CaveEntranceCells.AddDefaulted(2);
    this->CaveEntranceNeedNeighbourCells.AddDefaulted(4);
    this->TerraformBlockerLandscapeLayers.AddDefaulted(2);
    this->TerraformBlockerBiomes.AddDefaulted(2);
    this->AIPerceptionIgnoreDefaultClasses.AddDefaulted(3);
    this->LootDropWhiteListClasses.AddDefaulted(1);
    this->DefaultInventoryRules.AddDefaulted(1);
    this->CorruptionMarkerMinimumDistance = 500;
}

ULocDeveloperSettings* ULocDeveloperSettings::GetLocDeveloperSettings() {
    return NULL;
}


