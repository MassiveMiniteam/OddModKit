#include "NPCSimulationComponent.h"

UNPCSimulationComponent::UNPCSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Biome = NULL;
    this->VisualSortIndex = 0;
    this->QuestOverviewCategory = NULL;
}


