#pragma once
#include "CoreMinimal.h"
#include "GridNetworkAgentSimulationComponent.h"
#include "TrackNetworkAgentSimulationComponent.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UTrackNetworkAgentSimulationComponent : public UGridNetworkAgentSimulationComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInventoryComponent> AgentInventory;
    
public:
    UTrackNetworkAgentSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

