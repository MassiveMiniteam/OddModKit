#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "LogicScheduleSignalCommand.generated.h"

class ULogicOutputSimulationComponent;

UCLASS(Blueprintable)
class LOC_API ULogicScheduleSignalCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FName SignalChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 SignalValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    ULogicOutputSimulationComponent* LogicSimOut;
    
    ULogicScheduleSignalCommand();

};

