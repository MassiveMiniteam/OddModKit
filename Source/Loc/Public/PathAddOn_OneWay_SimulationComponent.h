#pragma once
#include "CoreMinimal.h"
#include "PathAddOnSimulationComponent.h"
#include "PathAddOn_OneWay_SimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPathAddOn_OneWay_SimulationComponent : public UPathAddOnSimulationComponent {
    GENERATED_BODY()
public:
    UPathAddOn_OneWay_SimulationComponent(const FObjectInitializer& ObjectInitializer);

};

