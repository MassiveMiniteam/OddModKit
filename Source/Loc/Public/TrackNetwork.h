#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GridNetwork.h"
#include "TrackNetwork.generated.h"

class UTrackNetworkSimulationComponent;

UCLASS(Blueprintable)
class ATrackNetwork : public AGridNetwork {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, UTrackNetworkSimulationComponent*> ConnectedCartStations;
    
public:
    ATrackNetwork(const FObjectInitializer& ObjectInitializer);

};

