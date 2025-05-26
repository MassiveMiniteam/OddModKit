#pragma once
#include "CoreMinimal.h"
#include "PathAddOnSimulationComponent.h"
#include "PathAddOn_ForceInteractionDirectionSingle_SimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPathAddOn_ForceInteractionDirectionSingle_SimulationComponent : public UPathAddOnSimulationComponent {
    GENERATED_BODY()
public:
    UPathAddOn_ForceInteractionDirectionSingle_SimulationComponent(const FObjectInitializer& ObjectInitializer);

};

