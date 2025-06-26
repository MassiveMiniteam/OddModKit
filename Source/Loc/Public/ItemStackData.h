#pragma once
#include "CoreMinimal.h"
#include "SerializedSimulationObject.h"
#include "ItemStackData.generated.h"

UCLASS(Blueprintable)
class UItemStackData : public USerializedSimulationObject {
    GENERATED_BODY()
public:
    UItemStackData();

};

