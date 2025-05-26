#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "CompleteConstructionSiteCommand.generated.h"

class UConstructionSiteObjectSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UCompleteConstructionSiteCommand : public USimulationCommand {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UConstructionSiteObjectSimulationComponent* ConstructionSiteComponent;
    
public:
    UCompleteConstructionSiteCommand();

};

