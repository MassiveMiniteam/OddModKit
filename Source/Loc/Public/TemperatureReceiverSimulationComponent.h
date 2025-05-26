#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "TemperatureReceiverDelegateDelegate.h"
#include "TemperatureReceiverSimulationComponent.generated.h"

class URecipeConfig;
class USelectableRecipesSimulationComponent;
class UTemperatureEfficiencyConfig;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UTemperatureReceiverSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTemperatureReceiverDelegate OnTemperatureReceiverUpdated;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTemperatureEfficiencyConfig* EfficiencyConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USelectableRecipesSimulationComponent* RecipesComponent;
    
public:
    UTemperatureReceiverSimulationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnRecipeChanged(USelectableRecipesSimulationComponent* Component, URecipeConfig* Config);
    
public:
    UFUNCTION(BlueprintPure)
    FInt32Interval GetOptimalEfficiencyRange() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTemperatureEfficiencyConfig* GetDefaultTemperatureEfficiencyConfig() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentTemperature() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTemperatureEfficiencyConfig* GetCurrentlyActiveTemperatureEfficiencyConfig() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetCurrentEfficiency() const;
    
};

