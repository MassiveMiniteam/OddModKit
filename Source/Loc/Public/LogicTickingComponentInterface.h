#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Fixed.h"
#include "LogicTickingComponentInterface.generated.h"

UINTERFACE(Blueprintable)
class ULogicTickingComponentInterface : public UInterface {
    GENERATED_BODY()
};

class ILogicTickingComponentInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void TickLogic(FFixed DeltaTime);
    
};

