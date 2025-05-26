#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "CopyToolUseable.h"
#include "PathAddOnSimulationComponent.h"
#include "PathAddOn_WaitForSpecifiedTime_SimulationComponent.generated.h"

class USimulationTimerComponent;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPathAddOn_WaitForSpecifiedTime_SimulationComponent : public UPathAddOnSimulationComponent, public ICopyToolUseable {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference TimerReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USimulationTimerComponent> Timer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> Stats;
    
public:
    UPathAddOn_WaitForSpecifiedTime_SimulationComponent(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

