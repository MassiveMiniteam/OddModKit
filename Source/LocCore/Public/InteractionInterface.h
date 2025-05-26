#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractionInterface.generated.h"

UINTERFACE(Blueprintable)
class LOCCORE_API UInteractionInterface : public UInterface {
    GENERATED_BODY()
};

class LOCCORE_API IInteractionInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Interact();
    
};

