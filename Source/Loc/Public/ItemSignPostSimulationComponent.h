#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "CopyToolUseable.h"
#include "ItemSignPostSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UItemSignPostSimulationComponent : public USimulationActorComponent, public ICopyToolUseable {
    GENERATED_BODY()
public:
    UItemSignPostSimulationComponent(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

