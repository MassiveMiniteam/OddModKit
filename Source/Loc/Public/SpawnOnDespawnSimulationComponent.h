#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "SpawnOnDespawnSimulationComponent.generated.h"

class ASimulationActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API USpawnOnDespawnSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ASimulationActor> SpawnActorClass;
    
public:
    USpawnOnDespawnSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

