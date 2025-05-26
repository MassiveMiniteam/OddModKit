#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Fixed.h"
#include "BossTokenGeneratorProcessRateChangedDelegate.h"
#include "BossTokenGeneratorSpeedChangedDelegate.h"
#include "ItemStack.h"
#include "ProcessRateOutputConfig.h"
#include "RegisteredSimulationComponent.h"
#include "BossTokenGenerator.generated.h"

class UBossTokenGeneratorSubsystem;
class UInventoryComponent;
class UItemConfig;
class UItemDecayComponent;
class USimulationTimerComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UBossTokenGenerator : public URegisteredSimulationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBossTokenGeneratorProcessRateChanged OnBossTokenProcessRateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBossTokenGeneratorSpeedChanged OnBossTargetSpeedValueChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemDecayComponent* ItemDecayComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 SelectedIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FProcessRateOutputConfig> ProcessRateToOutput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference BossTokenInventoryReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBossTokenGeneratorSubsystem* CachedBossTokenSubsystem;
    
public:
    UBossTokenGenerator(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetSelectedIndex(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    void SetBurnRateFactor(FFixed NewBurnRateFactor);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnTimerStopped(USimulationTimerComponent* SimulationTimerComponent);
    
    UFUNCTION(BlueprintCallable)
    void OnTimerStarted(USimulationTimerComponent* SimulationTimerComponent);
    
    UFUNCTION(BlueprintCallable)
    void OnItemDecayed(UItemDecayComponent* Component, UItemConfig* ItemConfig);
    
    UFUNCTION(BlueprintCallable)
    void OnDecayInventoryChanged(UItemDecayComponent* Component, UInventoryComponent* Inventory);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetProcessRateFactor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemDecayComponent* GetItemDecayComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FItemStack GetCurrentlyProducedItemStack() const;
    
};

