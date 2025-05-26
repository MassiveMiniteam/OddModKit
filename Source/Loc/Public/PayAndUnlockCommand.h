#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "ItemStack.h"
#include "PayAndUnlockCommand.generated.h"

class ASimulationActor;
class UInventoryComponent;
class UUnlockableDataAsset;

UCLASS(Blueprintable)
class LOC_API UPayAndUnlockCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UInventoryComponent* InventoryComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UUnlockableDataAsset* DataAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FItemStack> Cost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationActor* SourceActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bCostsCanBePaidFromSupplyChests;
    
    UPayAndUnlockCommand();

};

