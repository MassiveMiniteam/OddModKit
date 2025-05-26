#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "TemperatureRegulatorDelegateDelegate.h"
#include "TemperatureRegulatorSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UTemperatureRegulatorSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTemperatureRegulatorDelegate OnHeatModeChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bHeatMode;
    
public:
    UTemperatureRegulatorSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetHeatMode(bool bNewHeatMode);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetHeatMode() const;
    
};

