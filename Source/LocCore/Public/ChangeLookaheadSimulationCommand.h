#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "ChangeLookaheadSimulationCommand.generated.h"

UCLASS(Blueprintable)
class LOCCORE_API UChangeLookaheadSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 NewLookahead;
    
    UChangeLookaheadSimulationCommand();

};

