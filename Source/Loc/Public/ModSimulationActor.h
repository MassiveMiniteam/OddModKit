#pragma once
#include "CoreMinimal.h"
#include "LocCoreSavable.h"
#include "SimulationActor.h"
#include "ModSimulationActor.generated.h"

UCLASS(Blueprintable)
class LOC_API AModSimulationActor : public ASimulationActor, public ILocCoreSavable {
    GENERATED_BODY()
public:
    AModSimulationActor(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
    UFUNCTION()
    void OnAllSaveGameActorsLoadedAndRegistered() override PURE_VIRTUAL(OnAllSaveGameActorsLoadedAndRegistered,);
    
};

