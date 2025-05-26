#include "LogicInputPresentationComponent.h"

ULogicInputPresentationComponent::ULogicInputPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DirectionsToIndicate.AddDefaulted(4);
    this->TagForIndicator = TEXT("InputConnectorIndicator");
    this->TargetLogicInput = NULL;
}


