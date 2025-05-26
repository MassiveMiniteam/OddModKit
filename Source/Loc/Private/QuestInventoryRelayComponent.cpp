#include "QuestInventoryRelayComponent.h"
#include "Templates/SubclassOf.h"

UQuestInventoryRelayComponent::UQuestInventoryRelayComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->OwningActorType = NULL;
    this->Inventory = NULL;
}

TSubclassOf<ASimulationActor> UQuestInventoryRelayComponent::GetOwningActorType() const {
    return NULL;
}

UInventoryComponent* UQuestInventoryRelayComponent::GetInventory() const {
    return NULL;
}


