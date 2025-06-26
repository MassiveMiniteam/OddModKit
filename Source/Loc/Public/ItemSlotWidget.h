#pragma once
#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "Input/Events.h"
#include "ItemSlotChangedEventDelegate.h"
#include "NavInteractionEventDelegate.h"
#include "NavUserWidget.h"
#include "OnInteractionTimeUpdateDelegate.h"
#include "UIEventMouseDropInterface.h"
#include "ItemSlotWidget.generated.h"

class UHoldInteractionData;
class UInventoryComponent;
class UItemConfig;
class UObject;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UItemSlotWidget : public UNavUserWidget, public IUIEventMouseDropInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* Inventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* VisualInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SlotIndex;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemSlotChangedEvent OnItemSlotChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsSetup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreInInventoryHolder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsPrediction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowInteraction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBlockTakeInteraction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TransferPriority;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnInteractionTimeUpdate HoldUpdate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNavInteractionEvent OnFailedInteractionAttempt;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNavInteractionEvent OnInteractionStartedByPlayerEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNavInteractionEvent OnInteractionByPlayerEvent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle HoldInteractionTimerHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UHoldInteractionData* InteractionData;
    
public:
    UItemSlotWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateHoldInteractions();
    
    UFUNCTION(BlueprintCallable)
    void SlateHandleUnhovered();
    
    UFUNCTION(BlueprintCallable)
    void SlateHandleHovered();
    
    UFUNCTION(BlueprintCallable)
    void SlateHandleClicked();
    
public:
    UFUNCTION(BlueprintCallable)
    void Setup(UInventoryComponent* TargetInventory, int32 TargetSlotIndex, bool bInIsPrediction);
    
protected:
    UFUNCTION(BlueprintCallable)
    void PickupHalfStackOrDropSingleInteraction();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnVisualInventoryItemRemoved(UItemConfig* Config, int32 Amount, UObject* Origin);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnVisualInventoryItemAdded(UItemConfig* Config, int32 Amount, UObject* Origin);
    
    UFUNCTION(BlueprintCallable)
    bool OnTransferItemInteraction();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSetupWithInventory(UInventoryComponent* InInventoryComponent, int32 TargetSlotIndex, bool bInIsPrediction);
    
    UFUNCTION(BlueprintCallable)
    void OnInventorySlotChanged(const int32 TargetSlotIndex);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnInteractionReleasedMouseKeyboard(const FPointerEvent& MouseEvent);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnDropItem_Event();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEmpty() const;
    
    UFUNCTION(BlueprintCallable)
    void DropItemStack();
    
protected:
    UFUNCTION(BlueprintCallable)
    bool CallLeftMouseShiftClick();
    

    // Fix for true pure virtual functions not being implemented
};

