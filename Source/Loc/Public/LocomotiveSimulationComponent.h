#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "Fixed64.h"
#include "LocomotiveSimulationComponent.generated.h"

class UInventoryComponent;
class ULocomotiveStrategy;
class UPlayerInputForwardSimulationComponent;
class UStatsComponent;
class UTrainTracksAgentSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULocomotiveSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStatsComponent* StatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* WorkerInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPlayerInputForwardSimulationComponent* PlayerInputComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTrainTracksAgentSimulationComponent* TrainAgentComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULocomotiveStrategy* Strategy;
    
public:
    ULocomotiveSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool WantsToDriveForward() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool WantsToDriveBackward() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasPlayerInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasMovementBlockedStat() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed64 GetCurrentMovementSpeed() const;
    
};

