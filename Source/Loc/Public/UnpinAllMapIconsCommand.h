#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "UnpinAllMapIconsCommand.generated.h"

class ASimulationPlayer;

UCLASS(Blueprintable)
class LOC_API UUnpinAllMapIconsCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationPlayer* ExecutingPlayer;
    
    UUnpinAllMapIconsCommand();

};

