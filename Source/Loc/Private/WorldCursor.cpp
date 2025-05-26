#include "WorldCursor.h"

AWorldCursor::AWorldCursor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->HoveredSimulationActor = NULL;
    this->HoveredPresentationActor = NULL;
    this->MinOffsetRadiusOnHover = 75;
    this->CursorWidth = 100;
    this->LockOnMode = ELockOnMode::Free;
}

FVector AWorldCursor::UpdateAndGetValidThrowTargetPosition(bool bUseRayIntersection) {
    return FVector{};
}

void AWorldCursor::SetHoveredActor(APresentationActor* PresentationActor, ASimulationActor* SimulationActor) {
}


