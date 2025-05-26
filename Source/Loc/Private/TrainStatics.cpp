#include "TrainStatics.h"

UTrainStatics::UTrainStatics() {
}

void UTrainStatics::DeriveBestConnectionsFromPoles(UTrainTracksPoleBaseSimulationComponent* FirstPole, UTrainTracksPoleBaseSimulationComponent* SecondPole, FIntVector AlternativeSecondaryPosition, UTrainTracksPoleConnectionSimulationComponent*& FirstConnection, UTrainTracksPoleConnectionSimulationComponent*& SecondConnection) {
}

FFixed64Spline UTrainStatics::CalculateSplineFromConnectionPoints(const FSplineConnectionPoints& ConnectionPoints) {
    return FFixed64Spline{};
}

FFixed64Spline UTrainStatics::CalculateSplineFromConnection(const UTrainTracksPoleConnectionSimulationComponent* ConnectionA, const UTrainTracksPoleConnectionSimulationComponent* ConnectionB) {
    return FFixed64Spline{};
}

FSplineConnectionPoints UTrainStatics::CalculateSplineConnectionPointsForConnection(const UTrainTracksPoleConnectionSimulationComponent* ConnectionA, const UTrainTracksPoleConnectionSimulationComponent* ConnectionB) {
    return FSplineConnectionPoints{};
}

bool UTrainStatics::AreConnectionConditionsMet_ConnectionPoints(const FSplineConnectionPoints& ConnectionPoints) {
    return false;
}

bool UTrainStatics::AreConnectionConditionsMet_ConnectionComponents(UTrainTracksPoleConnectionSimulationComponent* ConnectionA, UTrainTracksPoleConnectionSimulationComponent* ConnectionB) {
    return false;
}


