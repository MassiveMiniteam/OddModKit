#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LocSimulationSubsystem.h"
#include "GridManagerEventDelegate.h"
#include "GridManagerTileEventDelegate.h"
#include "IntPointCollection.h"
#include "Templates/SubclassOf.h"
#include "GridNetworkManagerSubsystem.generated.h"

class AGridNetwork;
class ASimulationActor;
class ASimulationPlayer;
class UConstructableConfig;
class UGridNetworkSimulationComponent;

UCLASS(Abstract, Blueprintable)
class LOC_API UGridNetworkManagerSubsystem : public ULocSimulationSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGridNetworkSimulationComponent> GridNetworkComponentClass;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGridManagerTileEvent OnTilesChangeEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGridManagerEvent OnNetworkChangeEvent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AGridNetwork> NetworkType;
    
private:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, TWeakObjectPtr<AGridNetwork>> PositionToNetworkMapping;
    
public:
    UGridNetworkManagerSubsystem();

    UFUNCTION(BlueprintCallable)
    void Unbridge(AGridNetwork* Network, FIntPoint IntPoint, FIntPoint Int32Point);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnGridTileChanged(FIntPoint position);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<FIntPoint> GetPathTilePositionsForOverride(FIntPoint StartingTile, const UConstructableConfig* ConstructableConfig, const ASimulationPlayer* ExecutingSimulationPlayer) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AGridNetwork* FindNetworkAt(FIntPoint position) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UGridNetworkSimulationComponent* FindGridNetworkComponentAt(FIntPoint position) const;
    
    UFUNCTION(BlueprintCallable)
    TArray<FIntPointCollection> FindConnectedNeighbours(FIntPoint StartingPoint, int32 MaxDistanceInTiles, FIntPoint OptionalDirection, TArray<TSubclassOf<ASimulationActor>> BlockingActors);
    
    UFUNCTION(BlueprintCallable)
    bool BridgeNetworks(AGridNetwork* Network1, AGridNetwork* Network2, const FIntPoint& Point1, const FIntPoint& Point2);
    
};

