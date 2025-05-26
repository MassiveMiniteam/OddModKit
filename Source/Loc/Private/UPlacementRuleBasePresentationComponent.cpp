#include "UPlacementRuleBasePresentationComponent.h"
#include "Templates/SubclassOf.h"

UUPlacementRuleBasePresentationComponent::UUPlacementRuleBasePresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PlacementRuleListeningClass = NULL;
}


void UUPlacementRuleBasePresentationComponent::StopIndication(TSubclassOf<UGridPlacementRuleConfig> PlacementRuleConfig) {
}


void UUPlacementRuleBasePresentationComponent::StartIndication(TSubclassOf<UGridPlacementRuleConfig> PlacementRuleConfig) {
}


