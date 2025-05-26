#pragma once
#include "CoreMinimal.h"
#include "LocSimulationSubsystem.h"
#include "PresentationAsyncSpawnSubsystem.generated.h"

class ASimulationActor;

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class LOC_API UPresentationAsyncSpawnSubsystem : public ULocSimulationSubsystem {
    GENERATED_BODY()
public:
    UPresentationAsyncSpawnSubsystem();

private:
    UFUNCTION(BlueprintCallable)
    bool ShouldSpawnPresentationOnActorSpawn(ASimulationActor* SimulationActor);
    
};

