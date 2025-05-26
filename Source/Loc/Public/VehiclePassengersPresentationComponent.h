#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "VehiclePassengersPresentationComponent.generated.h"

class ASimulationActor;
class UVehicleSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UVehiclePassengersPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVehicleSimulationComponent* VehicleSimulationComponent;
    
public:
    UVehiclePassengersPresentationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSimActorRemoved(UVehicleSimulationComponent* Component, ASimulationActor* SimulationActor, int32 Index);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSimActorAdded(UVehicleSimulationComponent* Component, ASimulationActor* SimulationActor, int32 Index);
    
};

