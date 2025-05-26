#pragma once
#include "CoreMinimal.h"
#include "Components/RichTextBlockDecorator.h"
#include "LocRichTextButtonPromptDecorator.generated.h"

class UInputDeviceMapping;

UCLASS(Blueprintable)
class LOC_API ULocRichTextButtonPromptDecorator : public URichTextBlockDecorator {
    GENERATED_BODY()
public:
    ULocRichTextButtonPromptDecorator();

protected:
    UFUNCTION(BlueprintCallable)
    void OnInputDeviceChanged(UInputDeviceMapping* InputDevice);
    
};

