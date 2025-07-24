#pragma once
#include "CoreMinimal.h"
#include "GridObserverSimulationComponent.h"
#include "StepSensorStateChangedDelegateDelegate.h"
#include "StepSensorSimulationComponent.generated.h"

class AGrid;
class ULogicOutputSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UStepSensorSimulationComponent : public UGridObserverSimulationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStepSensorStateChangedDelegate OnPressedDownStateChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULogicOutputSimulationComponent* LogicOutput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGrid* Grid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsPressedDown;
    
public:
    UStepSensorSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsPressedDown() const;
    
};

