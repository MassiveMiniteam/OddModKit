#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "ProductioRateBoundTimerRateChangeEventDelegate.h"
#include "SimulationTimerComponent.h"
#include "ProductionRateBoundTimerComponent.generated.h"

class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UProductionRateBoundTimerComponent : public USimulationTimerComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProductioRateBoundTimerRateChangeEvent OnProductionRatePerMinuteChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed Interval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStatsComponent* StatsComponent;
    
public:
    UProductionRateBoundTimerComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetProductionRatePerMinute();
    
};

