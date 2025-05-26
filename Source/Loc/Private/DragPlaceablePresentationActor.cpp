#include "DragPlaceablePresentationActor.h"

ADragPlaceablePresentationActor::ADragPlaceablePresentationActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bUseRaycastingForPreview = true;
    this->Type = EGridDirectionVisualizationType::End;
    this->RotationInDegrees = 0;
    this->bIsOnCliff = false;
    this->CliffHeight = 0;
    this->MaxCliffHeightDiff = 0;
    this->bHasCliffConnection = false;
    this->bIsLowerRampCorner = false;
    this->bIsOnRamp = false;
    this->bIsTopPartOfRamp = false;
    this->bConsiderRampsAsCliffs = false;
    this->GridNetworkSimulationComponent = NULL;
    this->bIsInGhostMode = false;
    this->CurrentPlacmentState = -1;
}

void ADragPlaceablePresentationActor::UpdatePlacementStateEvent_Implementation(int32 NoneBlockedFree) {
}

void ADragPlaceablePresentationActor::UpdatePlacementState(int32 NoneBlockedFree) {
}

void ADragPlaceablePresentationActor::UpdateGridConnectionType(const TArray<FIntPoint>& NewConnections) {
}

void ADragPlaceablePresentationActor::UpdateConnection_Implementation(const TArray<FIntPoint>& NewConnections) {
}

void ADragPlaceablePresentationActor::SetPlacementOrderIndex_Implementation(int32 Index) {
}

void ADragPlaceablePresentationActor::SetGhostMode_Implementation(bool bIsGhostMode) {
}

void ADragPlaceablePresentationActor::OnGridNetworkUpdated(UGridNetworkSimulationComponent* Component) {
}

bool ADragPlaceablePresentationActor::GetGridConnectionType(const TArray<FIntPoint>& Connections, EGridDirectionVisualizationType& TypeOut, int32& RotationInDegreesOut) {
    return false;
}

TArray<FCliffConnection> ADragPlaceablePresentationActor::GetCliffConnections() {
    return TArray<FCliffConnection>();
}


