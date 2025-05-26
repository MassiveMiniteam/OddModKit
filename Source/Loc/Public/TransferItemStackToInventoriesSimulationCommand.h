#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "TransferItemStackToInventoriesSimulationCommand.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable)
class LOC_API UTransferItemStackToInventoriesSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UInventoryComponent* FromInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UInventoryComponent*> TargetInventories;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 FromSlotIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bPrioritizeMinions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsFirstPredictionCall;
    
    UTransferItemStackToInventoriesSimulationCommand();

    UFUNCTION(BlueprintCallable)
    void Setup(UInventoryComponent* InFromInventory, int32 FromIndex, TArray<UInventoryComponent*> InToInventories, bool bInPrioritizeMinions);
    
};

