#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "ItemStack.h"
#include "BuyItemStacksCommand.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable)
class LOC_API UBuyItemStacksCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UInventoryComponent* PayCostInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FItemStack> Costs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UInventoryComponent* BoughtItemTargetInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FItemStack> ItemsToBuy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bCostsCanBePaidFromSupplyChests;
    
    UBuyItemStacksCommand();

};

