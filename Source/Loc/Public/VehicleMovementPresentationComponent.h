#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "VehicleMovementPresentationComponent.generated.h"

class ASimulationActor;
class ASimulationPlayer;
class UPositionSimulationComponent;
class UVehicleSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UVehicleMovementPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASimulationPlayer* CurrentDriver;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> PositionSimulationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVehicleSimulationComponent* VehicleSimulationComponent;
    
public:
    UVehicleMovementPresentationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void ResetLastAndPrevPositions();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnSimActorRemoved(UVehicleSimulationComponent* Component, ASimulationActor* SimulationActor, int32 Index);
    
    UFUNCTION(BlueprintCallable)
    void OnSimActorAdded(UVehicleSimulationComponent* Component, ASimulationActor* SimulationActor, int32 Index);
    
};

