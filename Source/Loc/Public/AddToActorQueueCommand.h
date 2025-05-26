#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "AddActorToQueueCommand_DelegateDelegate.h"
#include "AddToActorQueueCommand.generated.h"

class ASimulationActor;
class UActorQueueSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UAddToActorQueueCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAddActorToQueueCommand_Delegate OnAddActorToQueueCommandExecuted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UActorQueueSimulationComponent* Queue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationActor* Actor;
    
    UAddToActorQueueCommand();

};

