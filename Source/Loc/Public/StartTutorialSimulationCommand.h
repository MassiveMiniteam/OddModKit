#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "StartTutorialSimulationCommand.generated.h"

class UTutorialManagerSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UStartTutorialSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UTutorialManagerSimulationComponent* TutorialManager;
    
public:
    UStartTutorialSimulationCommand();

};

