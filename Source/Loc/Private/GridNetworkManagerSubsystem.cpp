#include "GridNetworkManagerSubsystem.h"
#include "Templates/SubclassOf.h"

UGridNetworkManagerSubsystem::UGridNetworkManagerSubsystem() {
    this->GridNetworkComponentClass = NULL;
    this->NetworkType = NULL;
}

void UGridNetworkManagerSubsystem::Unbridge(AGridNetwork* Network, FIntPoint IntPoint, FIntPoint Int32Point) {
}

void UGridNetworkManagerSubsystem::OnGridTileChanged(FIntPoint position) {
}

TArray<FIntPoint> UGridNetworkManagerSubsystem::GetPathTilePositionsForOverride(FIntPoint StartingTile, const UConstructableConfig* ConstructableConfig, const ASimulationPlayer* ExecutingSimulationPlayer) const {
    return TArray<FIntPoint>();
}

AGridNetwork* UGridNetworkManagerSubsystem::FindNetworkAt(FIntPoint position) const {
    return NULL;
}

UGridNetworkSimulationComponent* UGridNetworkManagerSubsystem::FindGridNetworkComponentAt(FIntPoint position) const {
    return NULL;
}

TArray<FIntPointCollection> UGridNetworkManagerSubsystem::FindConnectedNeighbours(FIntPoint StartingPoint, int32 MaxDistanceInTiles, FIntPoint OptionalDirection, TArray<TSubclassOf<ASimulationActor>> BlockingActors) {
    return TArray<FIntPointCollection>();
}

bool UGridNetworkManagerSubsystem::BridgeNetworks(AGridNetwork* Network1, AGridNetwork* Network2, const FIntPoint& Point1, const FIntPoint& Point2) {
    return false;
}


