#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "PositionActorUpdateSimulationComponent.generated.h"

class UPositionSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPositionActorUpdateSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPositionSimulationComponent* PositionComp;
    
public:
    UPositionActorUpdateSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

