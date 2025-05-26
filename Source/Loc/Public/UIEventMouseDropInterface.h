#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Input/Events.h"
#include "UIEventMouseDropInterface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UUIEventMouseDropInterface : public UInterface {
    GENERATED_BODY()
};

class IUIEventMouseDropInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool OnMouseDropEvent(const FPointerEvent& MouseEvent);
    
};

