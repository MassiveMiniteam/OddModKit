#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InputReceiver.generated.h"

class UInputActionData;

UINTERFACE(Blueprintable, MinimalAPI)
class UInputReceiver : public UInterface {
    GENERATED_BODY()
};

class IInputReceiver : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnInputEvent(UInputActionData* InputData);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    int32 GetInputPriority();
    
};

