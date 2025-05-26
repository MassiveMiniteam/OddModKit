#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimulationActorComponent.h"
#include "OnGridNetworkSimulationComponentUpdatedDelegate.h"
#include "GridNetworkSimulationComponent.generated.h"

class UGridNetworkSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGridNetworkSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint ConnectorPositionOffset;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGridNetworkSimulationComponentUpdated OnGridNetworkSimulationComponentUpdated;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> Connections;
    
public:
    UGridNetworkSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateConnection(const TArray<FIntPoint>& NewConnections);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsConnectedNeighbour(UGridNetworkSimulationComponent* CompareComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint GetGridPosition() const;
    
};

