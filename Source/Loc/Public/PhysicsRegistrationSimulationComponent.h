#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "PhysicsRegistrationSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPhysicsRegistrationSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPhysicsRegistrationSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

