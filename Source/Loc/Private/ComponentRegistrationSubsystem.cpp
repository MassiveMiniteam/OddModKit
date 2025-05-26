#include "ComponentRegistrationSubsystem.h"

UComponentRegistrationSubsystem::UComponentRegistrationSubsystem() {
}

TArray<URegisteredSimulationComponent*> UComponentRegistrationSubsystem::GetRegisteredComponents() const {
    return TArray<URegisteredSimulationComponent*>();
}


