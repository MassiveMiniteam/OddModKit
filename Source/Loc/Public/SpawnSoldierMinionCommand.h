#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimulationCommand.h"
#include "ItemStack.h"
#include "SpawnSoldierMinionCommand.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable)
class LOC_API USpawnSoldierMinionCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FItemStack ItemStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntVector WorldPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Rotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UInventoryComponent* Inventory;
    
    USpawnSoldierMinionCommand();

};

