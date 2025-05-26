#pragma once
#include "CoreMinimal.h"
#include "InputContext.h"
#include "InputContextConstructionToolBelt.generated.h"

class ALocPlayerController;
class UInputActionData;

UCLASS(Abstract, Blueprintable)
class LOC_API UInputContextConstructionToolBelt : public UInputContext {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_QuickSelect_Next;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_QuickSelect_Previous;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_QuickSelect_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_QuickSelect_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_QuickSelect_3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_QuickSelect_4;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_QuickSelect_5;
    
public:
    UInputContextConstructionToolBelt();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInputAction_QuickSelect_Previous(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInputAction_QuickSelect_Next(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInputAction_QuickSelect_5(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInputAction_QuickSelect_4(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInputAction_QuickSelect_3(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInputAction_QuickSelect_2(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInputAction_QuickSelect_1(UInputActionData* InputAction, ALocPlayerController* Player);
    
};

