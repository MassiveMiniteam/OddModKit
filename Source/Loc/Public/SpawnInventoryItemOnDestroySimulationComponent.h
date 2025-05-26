#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "SpawnInventoryItemOnDestroySimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API USpawnInventoryItemOnDestroySimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    USpawnInventoryItemOnDestroySimulationComponent(const FObjectInitializer& ObjectInitializer);

};

