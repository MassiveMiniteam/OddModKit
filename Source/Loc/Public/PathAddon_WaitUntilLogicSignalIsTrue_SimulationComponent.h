#pragma once
#include "CoreMinimal.h"
#include "PathAddOnSimulationComponent.h"
#include "PathAddon_WaitUntilLogicSignalIsTrue_SimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPathAddon_WaitUntilLogicSignalIsTrue_SimulationComponent : public UPathAddOnSimulationComponent {
    GENERATED_BODY()
public:
    UPathAddon_WaitUntilLogicSignalIsTrue_SimulationComponent(const FObjectInitializer& ObjectInitializer);

};

