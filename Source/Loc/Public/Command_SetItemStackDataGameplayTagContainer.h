#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SimulationCommand.h"
#include "Command_SetItemStackDataGameplayTagContainer.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable)
class LOC_API UCommand_SetItemStackDataGameplayTagContainer : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UInventoryComponent* Inventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 SlotIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Tags;
    
    UCommand_SetItemStackDataGameplayTagContainer();

};

