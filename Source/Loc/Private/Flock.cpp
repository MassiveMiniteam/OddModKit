#include "Flock.h"
#include "Components/InstancedStaticMeshComponent.h"

AFlock::AFlock(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->NumEntities = 20;
    this->MinSpeed = 1000.00f;
    this->MaxSpeed = 1500.00f;
    this->PerceptionRadius = 2000.00f;
    this->AvoidanceRadius = 750.00f;
    this->AlignmentWeight = 250.00f;
    this->CohesionWeight = 200.00f;
    this->SeparationWeight = 500.00f;
    this->GravitationImpact = 0.02f;
    this->CloseTooGroundThreshold = 300.00f;
    this->UpperLimit = 1000.00f;
    this->InstancedStaticMeshComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Entity Meshes"));
    this->Entities.AddDefaulted(20);
}

void AFlock::InitiateLanding() {
}

void AFlock::InitiateFlying() {
}


