#include "MinionControllerPresentationLibrary.h"

UMinionControllerPresentationLibrary::UMinionControllerPresentationLibrary() {
}

TArray<ASimulationActor*> UMinionControllerPresentationLibrary::GetThrowableDeployedMinions(const UMinionControllerSimulationBaseComponent* Controller, int32 ControlGroupIndex) {
    return TArray<ASimulationActor*>();
}

int32 UMinionControllerPresentationLibrary::GetThrowableDeployedMinionCount(const UMinionControllerSimulationBaseComponent* Controller, int32 MinionSlotIndex) {
    return 0;
}

ASimulationActor* UMinionControllerPresentationLibrary::GetNextDeployedAndThrowableMinion(UMinionControllerSimulationBaseComponent* Controller, FMinionConfigTagPair ConfigTagPair) {
    return NULL;
}

TArray<ASimulationActor*> UMinionControllerPresentationLibrary::GetAllThrowableDeployedMinions(const UMinionControllerSimulationBaseComponent* Controller) {
    return TArray<ASimulationActor*>();
}

bool UMinionControllerPresentationLibrary::AreAllMinionsThrowable(const UMinionControllerSimulationBaseComponent* Controller) {
    return false;
}


