#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "ClearInventoryMetaSlotSimulationCommand.generated.h"

class UInventoryMetaSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UClearInventoryMetaSlotSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UInventoryMetaSimulationComponent* MetaSimulationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Slot;
    
    UClearInventoryMetaSlotSimulationCommand();

};

