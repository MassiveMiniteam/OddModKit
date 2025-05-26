#pragma once
#include "CoreMinimal.h"
#include "RegisteredSimulationComponent.h"
#include "WaterSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UWaterSimulationComponent : public URegisteredSimulationComponent {
    GENERATED_BODY()
public:
    UWaterSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

