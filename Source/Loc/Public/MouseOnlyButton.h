#pragma once
#include "CoreMinimal.h"
#include "Components/Button.h"
#include "MouseOnlyButton.generated.h"

class UInputActionData;
class UInputDeviceMapping;

UCLASS(Blueprintable)
class LOC_API UMouseOnlyButton : public UButton {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* TriggerInputActionData;
    
    UMouseOnlyButton();

protected:
    UFUNCTION(BlueprintCallable)
    void OnInputDeviceChanged(UInputDeviceMapping* Device);
    
    UFUNCTION(BlueprintCallable)
    void OnHandleReleased();
    
    UFUNCTION(BlueprintCallable)
    void OnHandlePressed();
    
};

