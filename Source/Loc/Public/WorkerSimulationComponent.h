#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "WorkerSimulationComponent.generated.h"

class UCarrySimulationComponent;
class UPathNetworkAgentSimulationComponent;
class UStatsComponent;
class USubGridMovementSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UWorkerSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UCarrySimulationComponent> CarrySimulationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USubGridMovementSimulationComponent> SubGridMovementComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPathNetworkAgentSimulationComponent> PathNetworkAgentComp;
    
public:
    UWorkerSimulationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnSubGridPositionChanged(USubGridMovementSimulationComponent* Component);
    
};

