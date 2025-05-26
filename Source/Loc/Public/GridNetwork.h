#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LocCoreSavable.h"
#include "SimulationActor.h"
#include "ArrayOfGridPositions.h"
#include "GridNetworkEdge.h"
#include "OnGridNetworkEventDelegate.h"
#include "GridNetwork.generated.h"

class UGridNetworkAgentSimulationComponent;

UCLASS(Abstract, Blueprintable)
class AGridNetwork : public ASimulationActor, public ILocCoreSavable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGridNetworkEvent OnGridNetworkUpdated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGridNetworkEvent OnGridNetworkDestroyed;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> Positions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FGridNetworkEdge> Edges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, FArrayOfGridPositions> OutgoingEdges;
    
public:
    AGridNetwork(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool PositionAndHeadingIntoDeadEnd(const UGridNetworkAgentSimulationComponent* Agent, FIntPoint CurrentPosition, FIntPoint CurrentHeading) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FIntPoint> GetAllReachablePositionsInWholeNetwork(const FIntPoint& StartingPosition) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FIntPoint> GetAllReachableNeighbours(const UGridNetworkAgentSimulationComponent* Agent, FIntPoint position) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FIntPoint> GetAllPositions() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanMoveInDirection(const UGridNetworkAgentSimulationComponent* Agent, FIntPoint FromPosition, FIntPoint Direction) const;
    

    // Fix for true pure virtual functions not being implemented
    UFUNCTION()
    void OnAllSaveGameActorsLoadedAndRegistered() override PURE_VIRTUAL(OnAllSaveGameActorsLoadedAndRegistered,);
    
};

