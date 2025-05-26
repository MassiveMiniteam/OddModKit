#pragma once
#include "CoreMinimal.h"
#include "GridNetworkSimulationComponent.h"
#include "WaterNetworkSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UWaterNetworkSimulationComponent : public UGridNetworkSimulationComponent {
    GENERATED_BODY()
public:
    UWaterNetworkSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

