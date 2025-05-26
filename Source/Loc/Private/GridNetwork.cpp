#include "GridNetwork.h"

AGridNetwork::AGridNetwork(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool AGridNetwork::PositionAndHeadingIntoDeadEnd(const UGridNetworkAgentSimulationComponent* Agent, FIntPoint CurrentPosition, FIntPoint CurrentHeading) const {
    return false;
}

TArray<FIntPoint> AGridNetwork::GetAllReachablePositionsInWholeNetwork(const FIntPoint& StartingPosition) const {
    return TArray<FIntPoint>();
}

TArray<FIntPoint> AGridNetwork::GetAllReachableNeighbours(const UGridNetworkAgentSimulationComponent* Agent, FIntPoint position) const {
    return TArray<FIntPoint>();
}

TArray<FIntPoint> AGridNetwork::GetAllPositions() const {
    return TArray<FIntPoint>();
}

bool AGridNetwork::CanMoveInDirection(const UGridNetworkAgentSimulationComponent* Agent, FIntPoint FromPosition, FIntPoint Direction) const {
    return false;
}


