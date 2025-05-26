#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "AutoSortInventoryCommand.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable)
class LOC_API UAutoSortInventoryCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UInventoryComponent* Inventory;
    
    UAutoSortInventoryCommand();

};

