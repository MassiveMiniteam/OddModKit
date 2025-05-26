#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "ConfigureLogicSensorSimulationCommand.generated.h"

class ULogicSensorBaseSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UConfigureLogicSensorSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    ULogicSensorBaseSimulationComponent* LogicSensor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Value;
    
    UConfigureLogicSensorSimulationCommand();

};

