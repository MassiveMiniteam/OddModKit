#include "UnitPresentation.h"
#include "Net/UnrealNetwork.h"

AUnitPresentation::AUnitPresentation(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SimulationActorNameIndex = 0;
}

void AUnitPresentation::OnSimulationActorNameIndexReplicated() {
}

void AUnitPresentation::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AUnitPresentation, SimulationActorNameIndex);
}


