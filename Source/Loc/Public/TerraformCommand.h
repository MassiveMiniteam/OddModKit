#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimulationCommand.h"
#include "ItemStack.h"
#include "TerraformPosition.h"
#include "TerraformCommand.generated.h"

class UInventoryComponent;
class UObject;

UCLASS(Blueprintable)
class LOC_API UTerraformCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UInventoryComponent* PayCostInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FItemStack> Costs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FTerraformPosition> Targets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint CenterGridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bDigUp;
    
    UTerraformCommand();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static bool CanTerraformPosition(const UObject* WorldContext, FTerraformPosition Target);
    
};

