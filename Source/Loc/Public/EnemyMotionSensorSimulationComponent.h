#pragma once
#include "CoreMinimal.h"
#include "LogicSensorBaseSimulationComponent.h"
#include "EnemyMotionSensorSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UEnemyMotionSensorSimulationComponent : public ULogicSensorBaseSimulationComponent {
    GENERATED_BODY()
public:
    UEnemyMotionSensorSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

