#pragma once
#include "CoreMinimal.h"
#include "InputContext.h"
#include "ItemInputContext.generated.h"

class ALocPlayerController;
class UInputActionData;
class UInventoryComponent;

UCLASS(Blueprintable)
class LOC_API UItemInputContext : public UInputContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* Inventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SlotIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* RotateLeftAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* RotateRightAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* UseItemAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* CancelAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* UseSpecialAction;
    
    UItemInputContext();

protected:
    UFUNCTION(BlueprintCallable)
    void OnUseSpecialInput(UInputActionData* InputAction, ALocPlayerController* Player);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnUseSpecial();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnUseItemInput(UInputActionData* InputAction, ALocPlayerController* Player);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnUseItem();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRotateRightInput(UInputActionData* InputAction, ALocPlayerController* Player);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnRotateRight();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRotateLeftInput(UInputActionData* InputAction, ALocPlayerController* Player);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnRotateLeft();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnCancelInput(UInputActionData* InputAction, ALocPlayerController* Player);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnCancel();
    
};

