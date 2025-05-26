#pragma once
#include "CoreMinimal.h"
#include "ComponentRegistrationSubsystem.h"
#include "WaterSimulationSubsystem.generated.h"

UCLASS(Blueprintable)
class UWaterSimulationSubsystem : public UComponentRegistrationSubsystem {
    GENERATED_BODY()
public:
    UWaterSimulationSubsystem();

};

