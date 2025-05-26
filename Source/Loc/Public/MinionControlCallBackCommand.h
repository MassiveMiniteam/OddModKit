#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "MinionControlCallBackCommand.generated.h"

class UControllableMinionSimulationComponent;
class UMinionControllerSimulationBaseComponent;

UCLASS(Blueprintable)
class LOC_API UMinionControlCallBackCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UMinionControllerSimulationBaseComponent* MinionController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UControllableMinionSimulationComponent* ControllableMinionComponent;
    
    UMinionControlCallBackCommand();

};

