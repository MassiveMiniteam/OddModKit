#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LocCoreSavable.h"
#include "SerializedSimulationObject.generated.h"

UCLASS(Blueprintable)
class LOCCORE_API USerializedSimulationObject : public UObject, public ILocCoreSavable {
    GENERATED_BODY()
public:
    USerializedSimulationObject();


    // Fix for true pure virtual functions not being implemented
    UFUNCTION()
    void OnAllSaveGameActorsLoadedAndRegistered() override PURE_VIRTUAL(OnAllSaveGameActorsLoadedAndRegistered,);
    
};

