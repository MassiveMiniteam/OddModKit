#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "SetMotionSensorTargetingIndexCommand.generated.h"

class ULogicSensorBaseSimulationComponent;

UCLASS(Blueprintable)
class LOC_API USetMotionSensorTargetingIndexCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    ULogicSensorBaseSimulationComponent* LogicSensorComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Index;
    
    USetMotionSensorTargetingIndexCommand();

};

