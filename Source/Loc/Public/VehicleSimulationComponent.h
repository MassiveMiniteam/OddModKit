#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "VehicleEvent_SimulationActorAndIndexDelegate.h"
#include "VehicleSimulationComponent.generated.h"

class ASimulationActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UVehicleSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVehicleEvent_SimulationActorAndIndex OnSimulationActorAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVehicleEvent_SimulationActorAndIndex OnSimulationActorRemoved;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<ASimulationActor*> Seats;
    
public:
    UVehicleSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool TryAddSimulationActor(ASimulationActor* InSimulationActor);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveSimulationActor(ASimulationActor* InSimulationActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasOccupiedSeats() const;
    
    UFUNCTION(BlueprintCallable)
    int32 GetFreeSeat();
    
};

