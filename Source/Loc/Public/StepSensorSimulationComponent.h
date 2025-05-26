#pragma once
#include "CoreMinimal.h"
#include "LogicSensorBaseSimulationComponent.h"
#include "StepSensorSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UStepSensorSimulationComponent : public ULogicSensorBaseSimulationComponent {
    GENERATED_BODY()
public:
    UStepSensorSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

