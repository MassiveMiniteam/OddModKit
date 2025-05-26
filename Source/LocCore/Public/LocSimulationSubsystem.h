#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "LocSimulationSubsystem.generated.h"

UCLASS(Abstract, Blueprintable)
class LOCCORE_API ULocSimulationSubsystem : public UWorldSubsystem {
    GENERATED_BODY()
public:
    ULocSimulationSubsystem();

};

