#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SimulationCommand.h"
#include "ItemStack.h"
#include "RemoveMinionFromWorkstationAndTryAssignToPlayer.generated.h"

class ASimulationPlayer;
class UInventoryComponent;

UCLASS(Blueprintable)
class LOC_API URemoveMinionFromWorkstationAndTryAssignToPlayer : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationPlayer* SimulationPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UInventoryComponent* WorkstationInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 InventorySlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FItemStack CallbackItemStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGameplayTag StateGroupAfterSpawn;
    
    URemoveMinionFromWorkstationAndTryAssignToPlayer();

};

