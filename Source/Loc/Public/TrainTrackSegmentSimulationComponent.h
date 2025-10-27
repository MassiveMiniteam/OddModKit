#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "Fixed64.h"
#include "Fixed64Spline.h"
#include "Fixed64SplinePoint.h"
#include "TrainTrackSegmentSimulationComponent.generated.h"

class UPositionSimulationComponent;
class UTrainTracksAgentSimulationComponent;
class UTrainTracksPoleBaseSimulationComponent;
class UTrainTracksPoleConnectionSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UTrainTrackSegmentSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UTrainTracksPoleConnectionSimulationComponent> ConnectionStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UTrainTracksPoleConnectionSimulationComponent> ConnectionEnd;
    
    UPROPERTY(EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UTrainTracksAgentSimulationComponent>> AgentsOnThisSegment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> CachedPositionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FFixed64SplinePoint> OverwriteSplinePoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bTrainIgnoresSlope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 FixedAmountOfSegments;
    
public:
    UTrainTrackSegmentSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateCachedSpline();
    
    UFUNCTION(BlueprintCallable)
    void SetTrainIgnoresSlope(bool bIgnoreSlope);
    
    UFUNCTION(BlueprintCallable)
    void SetOverwriteSpline(const TArray<FFixed64SplinePoint>& SplinePoints);
    
    UFUNCTION(BlueprintCallable)
    void SetFixedAmountOfSegments(int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    void RemoveConnections();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOccupied() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsConnectedTo(const UTrainTracksPoleBaseSimulationComponent* Pole) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetTrainIgnoresSlope() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed64 GetLength() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetFixedAmountOfSegments() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTrainTracksPoleConnectionSimulationComponent* GetConnectedPoleStart() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTrainTracksPoleConnectionSimulationComponent* GetConnectedPoleEnd() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed64Spline GetCachedTrackSpline() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<UTrainTracksAgentSimulationComponent*> GetAgentsOnThisSegment() const;
    
    UFUNCTION(BlueprintCallable)
    void ConnectTo(UTrainTracksPoleConnectionSimulationComponent* Connection);
    
};

