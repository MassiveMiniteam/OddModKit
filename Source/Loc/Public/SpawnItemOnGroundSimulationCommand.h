#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimulationCommand.h"
#include "ItemStack.h"
#include "SpawnItemOnGroundSimulationCommand.generated.h"

UCLASS(Blueprintable)
class LOC_API USpawnItemOnGroundSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FItemStack ItemStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntVector WorldPosition;
    
    USpawnItemOnGroundSimulationCommand();

};

