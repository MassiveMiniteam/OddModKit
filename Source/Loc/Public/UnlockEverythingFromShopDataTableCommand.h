#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "UnlockEverythingFromShopDataTableCommand.generated.h"

class UDataTable;

UCLASS(Blueprintable)
class LOC_API UUnlockEverythingFromShopDataTableCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UDataTable* DataTable;
    
    UUnlockEverythingFromShopDataTableCommand();

};

