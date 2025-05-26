#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "MinionControlSpawnLoadoutCommand.generated.h"

class UInventoryComponent;
class UMinionControllerSimulationBaseComponent;

UCLASS(Blueprintable)
class LOC_API UMinionControlSpawnLoadoutCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UInventoryComponent* NewMinionInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UMinionControllerSimulationBaseComponent* MinionController;
    
    UMinionControlSpawnLoadoutCommand();

};

