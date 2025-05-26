#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "MapTeleportPresentationComponent.generated.h"

class ASimulationActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UMapTeleportPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
    UMapTeleportPresentationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnTeleportDone(ASimulationActor* SimulationActor);
    
};

