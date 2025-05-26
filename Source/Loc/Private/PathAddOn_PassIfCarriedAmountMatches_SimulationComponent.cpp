#include "PathAddOn_PassIfCarriedAmountMatches_SimulationComponent.h"

UPathAddOn_PassIfCarriedAmountMatches_SimulationComponent::UPathAddOn_PassIfCarriedAmountMatches_SimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CompareRule = EPathAddOnAmountCompareRule::Equal;
    this->StatsComponent = NULL;
}

void UPathAddOn_PassIfCarriedAmountMatches_SimulationComponent::SetCompareRule(EPathAddOnAmountCompareRule ModeIn) {
}

EPathAddOnAmountCompareRule UPathAddOn_PassIfCarriedAmountMatches_SimulationComponent::GetCompareRule() const {
    return EPathAddOnAmountCompareRule::Equal;
}


