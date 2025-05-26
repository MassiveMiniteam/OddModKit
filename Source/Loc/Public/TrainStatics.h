#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Fixed64Spline.h"
#include "SplineConnectionPoints.h"
#include "TrainStatics.generated.h"

class UTrainTracksPoleBaseSimulationComponent;
class UTrainTracksPoleConnectionSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UTrainStatics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UTrainStatics();

    UFUNCTION(BlueprintCallable)
    static void DeriveBestConnectionsFromPoles(UTrainTracksPoleBaseSimulationComponent* FirstPole, UTrainTracksPoleBaseSimulationComponent* SecondPole, FIntVector AlternativeSecondaryPosition, UTrainTracksPoleConnectionSimulationComponent*& FirstConnection, UTrainTracksPoleConnectionSimulationComponent*& SecondConnection);
    
    UFUNCTION(BlueprintCallable)
    static FFixed64Spline CalculateSplineFromConnectionPoints(const FSplineConnectionPoints& ConnectionPoints);
    
    UFUNCTION(BlueprintCallable)
    static FFixed64Spline CalculateSplineFromConnection(const UTrainTracksPoleConnectionSimulationComponent* ConnectionA, const UTrainTracksPoleConnectionSimulationComponent* ConnectionB);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSplineConnectionPoints CalculateSplineConnectionPointsForConnection(const UTrainTracksPoleConnectionSimulationComponent* ConnectionA, const UTrainTracksPoleConnectionSimulationComponent* ConnectionB);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool AreConnectionConditionsMet_ConnectionPoints(const FSplineConnectionPoints& ConnectionPoints);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool AreConnectionConditionsMet_ConnectionComponents(UTrainTracksPoleConnectionSimulationComponent* ConnectionA, UTrainTracksPoleConnectionSimulationComponent* ConnectionB);
    
};

