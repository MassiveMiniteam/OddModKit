#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "SetSimpleHashModeSimulationCommand.generated.h"

UCLASS(Blueprintable)
class LOC_API USetSimpleHashModeSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsSimpleHashMode;
    
    USetSimpleHashModeSimulationCommand();

};

