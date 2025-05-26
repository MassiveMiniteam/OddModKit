#pragma once
#include "CoreMinimal.h"
#include "RegisteredSimulationComponent.h"
#include "BlackBoardValidatorSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UBlackBoardValidatorSimulationComponent : public URegisteredSimulationComponent {
    GENERATED_BODY()
public:
    UBlackBoardValidatorSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

