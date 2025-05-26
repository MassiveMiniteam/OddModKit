#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "TransferItemStackSimulationCommand.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable)
class LOC_API UTransferItemStackSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UInventoryComponent* FromInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UInventoryComponent* TargetInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 FromSlotIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 TargetSlotIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 TargetAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bAllowSwap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bAllowTransferOverflow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bDropLeftovers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsFirstPredictionCall;
    
    UTransferItemStackSimulationCommand();

    UFUNCTION(BlueprintCallable)
    void Setup(UInventoryComponent* InFromInventory, int32 FromIndex, UInventoryComponent* InToInventory, int32 ToIndex, int32 InTargetAmount, bool bAllowSwapping, bool bAllowTransferingOverflow);
    
};

