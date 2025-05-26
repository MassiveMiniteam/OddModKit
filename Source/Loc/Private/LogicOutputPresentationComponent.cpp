#include "LogicOutputPresentationComponent.h"

ULogicOutputPresentationComponent::ULogicOutputPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DirectionsToIndicate.AddDefaulted(4);
    this->TagForIndicator = TEXT("OutputConnectorIndicator");
    this->TargetLogicOutput = NULL;
}

void ULogicOutputPresentationComponent::ScheduleSignal(FName Channel, int32 Value) {
}


