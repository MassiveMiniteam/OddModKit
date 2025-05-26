#include "SharedWorldActor.h"

ASharedWorldActor::ASharedWorldActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bHideOutlineAndHover = false;
    this->VisualLoggerActor = NULL;
    this->UnlockHandlingComponent = NULL;
}

void ASharedWorldActor::OnRunCommand(USimulationCommand* Command) {
}

UUnlockHandlingSimulationComponent* ASharedWorldActor::GetUnlockHandlingComponent() {
    return NULL;
}

FString ASharedWorldActor::GetBuildingCountsAsString() {
    return TEXT("");
}


