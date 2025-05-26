#pragma once
#include "CoreMinimal.h"
#include "LocSimulationSubsystem.h"
#include "PhysicsIncludeSubsystem.generated.h"

UCLASS(Blueprintable, Config=Game)
class LOC_API UPhysicsIncludeSubsystem : public ULocSimulationSubsystem {
    GENERATED_BODY()
public:
    UPhysicsIncludeSubsystem();

};

