#pragma once
#include "CoreMinimal.h"
#include "PathAddOnSimulationComponent.h"
#include "PathAddOn_StraightCrossing_SimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPathAddOn_StraightCrossing_SimulationComponent : public UPathAddOnSimulationComponent {
    GENERATED_BODY()
public:
    UPathAddOn_StraightCrossing_SimulationComponent(const FObjectInitializer& ObjectInitializer);

};

