#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ButtonPromptBarItem.h"
#include "ButtonPromptWidget.generated.h"

class UInputActionData;
class UInputDeviceMapping;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UButtonPromptWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputActionData;
    
    UButtonPromptWidget();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnActiveDeviceUpdate(UInputDeviceMapping* ActiveDevice);
    
    UFUNCTION(BlueprintCallable)
    void OnActiveDeviceChanged(UInputDeviceMapping* ActiveDevice);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void LoadWithButtonBarItem(FButtonPromptBarItem BarItem);
    
};

