#pragma once
#include "CoreMinimal.h"
#include "GridNetworkSimulationComponent.h"
#include "FenceNetworkSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UFenceNetworkSimulationComponent : public UGridNetworkSimulationComponent {
    GENERATED_BODY()
public:
    UFenceNetworkSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

