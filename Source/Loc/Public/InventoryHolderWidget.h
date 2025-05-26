#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/CanvasPanel.h"
#include "NavElementInterface.h"
#include "UIEventReceiverInterface.h"
#include "InventoryHolderWidget.generated.h"

class UInputActionData;
class UItemSlotWidget;
class UNavFocusPath;

UCLASS(Blueprintable)
class LOC_API UInventoryHolderWidget : public UCanvasPanel, public INavElementInterface, public IUIEventReceiverInterface {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UItemSlotWidget*> ItemSlots;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag Tag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag TagOfTransferInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHolderEnabled;
    
    UInventoryHolderWidget();

    UFUNCTION(BlueprintCallable)
    void SetHolderEnabled(bool bIsHolderEnabled);
    
    UFUNCTION(BlueprintCallable)
    void OverrideTransferTag(FGameplayTag OverrideTag);
    

    // Fix for true pure virtual functions not being implemented
    UFUNCTION()
    void OnProcessInput(UNavFocusPath* Path, int32 PathIndex, UInputActionData* InputData) override PURE_VIRTUAL(OnProcessInput,);
    
};

