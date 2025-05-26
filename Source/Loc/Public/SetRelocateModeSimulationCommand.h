#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "SetRelocateModeSimulationCommand.generated.h"

class AGridObject;
class ASimulationPlayer;

UCLASS(Blueprintable)
class LOC_API USetRelocateModeSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationPlayer* SimulationPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    AGridObject* GridObject;
    
    USetRelocateModeSimulationCommand();

};

