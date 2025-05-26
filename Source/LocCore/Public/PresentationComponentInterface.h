#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EDestructionReason.h"
#include "PresentationComponentInterface.generated.h"

UINTERFACE(Blueprintable)
class LOCCORE_API UPresentationComponentInterface : public UInterface {
    GENERATED_BODY()
};

class LOCCORE_API IPresentationComponentInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPresentationPreBegin(bool bIsLoading);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPresentationEnd(EDestructionReason Reason);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPresentationBegin(bool bIsLoading);
    
};

