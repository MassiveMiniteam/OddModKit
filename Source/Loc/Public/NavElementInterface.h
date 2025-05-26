#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "NavElementInterface.generated.h"

class UInputActionData;
class UNavFocusPath;

UINTERFACE(Blueprintable, MinimalAPI)
class UNavElementInterface : public UInterface {
    GENERATED_BODY()
};

class INavElementInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ProcessInput(UNavFocusPath* Path, int32 PathIndex, UInputActionData* InputData);
    
    UFUNCTION()
    virtual void OnProcessInput(UNavFocusPath* Path, int32 PathIndex, UInputActionData* InputData) PURE_VIRTUAL(OnProcessInput,);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnLostFocusFromPlayer();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnGainFocusByPlayer();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool Focus(bool bMouse);
    
};

