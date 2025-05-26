#pragma once
#include "CoreMinimal.h"
#include "InputContext.h"
#include "InputContextDefault.generated.h"

class ALocPlayerController;
class UInputActionData;

UCLASS(Blueprintable)
class LOC_API UInputContextDefault : public UInputContext {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* OpenInventoryAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* OpenPauseMenuAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* ToggleCursorModeAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* OpenDebugActorObserverAction;
    
public:
    UInputContextDefault();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnToggleCursorMode(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnOpenPauseMenu(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnOpenInventory(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnOpenDebugActorObserver(UInputActionData* InputAction, ALocPlayerController* Player);
    
};

