#include "ElementStateSimulationComponent.h"
#include "Templates/SubclassOf.h"

UElementStateSimulationComponent::UElementStateSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ElementMaterial = NULL;
    this->Stats = NULL;
    this->GameplayEffect = NULL;
    this->ApplyNaturalElementEffect = NULL;
}

void UElementStateSimulationComponent::SetElementState(FElementState NewState) {
}

bool UElementStateSimulationComponent::IsAtAtMaxStacksOfElement(const UElementDataAsset* Element) const {
    return false;
}

bool UElementStateSimulationComponent::IsAtAtMaxStacks() const {
    return false;
}

UElementDataAsset* UElementStateSimulationComponent::GetNaturalElement() const {
    return NULL;
}

FElementState UElementStateSimulationComponent::GetElementState() const {
    return FElementState{};
}

UElementMaterialDataAsset* UElementStateSimulationComponent::GetElementMaterial() const {
    return NULL;
}

TSubclassOf<UGameplayEffect> UElementStateSimulationComponent::GetElementalGameplayEffect(const UElementDataAsset* ElementDataAsset) const {
    return NULL;
}

UGameplayEffect* UElementStateSimulationComponent::GetCurrentGameplayEffect() const {
    return NULL;
}

int32 UElementStateSimulationComponent::GetCurrentElementStackAmount() const {
    return 0;
}

FFixed UElementStateSimulationComponent::GetCurrentElementRelativeStackAmount() const {
    return FFixed{};
}

int32 UElementStateSimulationComponent::GetCurrentElementMaxStacks() const {
    return 0;
}

bool UElementStateSimulationComponent::CurrentElementIsNaturalElement() const {
    return false;
}

void UElementStateSimulationComponent::ApplyElement(FElementState Element) {
}


