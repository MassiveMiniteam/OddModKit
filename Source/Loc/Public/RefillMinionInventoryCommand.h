#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "RefillMinionInventoryCommand.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable)
class LOC_API URefillMinionInventoryCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UInventoryComponent* MinionInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UInventoryComponent* ProviderInventory;
    
    URefillMinionInventoryCommand();

};

