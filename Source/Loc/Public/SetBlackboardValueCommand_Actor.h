#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "SetBlackboardValueCommand_Actor.generated.h"

class AActor;
class USimulationBlackboardComponent;

UCLASS(Blueprintable)
class LOC_API USetBlackboardValueCommand_Actor : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    AActor* Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FName KeyName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    USimulationBlackboardComponent* Blackboard;
    
    USetBlackboardValueCommand_Actor();

};

