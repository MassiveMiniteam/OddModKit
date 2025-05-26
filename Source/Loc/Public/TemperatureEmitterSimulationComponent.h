#pragma once
#include "CoreMinimal.h"
#include "RegisteredSimulationComponent.h"
#include "TemperatureEmitterChangedEventDelegate.h"
#include "TemperatureEmitterSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UTemperatureEmitterSimulationComponent : public URegisteredSimulationComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 EmittedTemperature;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Radius;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTemperatureEmitterChangedEvent OnNewTemperatureSet;
    
public:
    UTemperatureEmitterSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetEmittedTemperature(int32 NewTemperatureValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRadius() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetEmittedTemperature() const;
    
};

