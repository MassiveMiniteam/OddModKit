#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "RemoveFromActorQueueCommand.generated.h"

class ASimulationActor;
class UActorQueueSimulationComponent;

UCLASS(Blueprintable)
class LOC_API URemoveFromActorQueueCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UActorQueueSimulationComponent* Queue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationActor* Actor;
    
    URemoveFromActorQueueCommand();

};

