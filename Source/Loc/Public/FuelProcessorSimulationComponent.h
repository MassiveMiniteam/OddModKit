#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "FuelProcessorBurnRateChangeEventDelegate.h"
#include "FuelProcessorSimulationComponent.generated.h"

class UDifficultySettingsSubsystem;
class UInventoryComponent;
class UItemConfig;
class UItemDecayComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UFuelProcessorSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFuelProcessorBurnRateChangeEvent OnBurnRateChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemDecayComponent* ItemDecayComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed BurnRateFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UItemConfig* LastFuelConfig;
    
public:
    UFuelProcessorSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetBurnRateFactor(FFixed NewBurnRateFactor);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnItemDecayed(UItemDecayComponent* Component, UItemConfig* ItemConfig);
    
    UFUNCTION(BlueprintCallable)
    void OnDifficultySettingsChanged(UDifficultySettingsSubsystem* Subsystem);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnDecayInventoryChanged(UItemDecayComponent* Component, UInventoryComponent* Inventory);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemDecayComponent* GetItemDecayComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetBurnRateFactor() const;
    
};

