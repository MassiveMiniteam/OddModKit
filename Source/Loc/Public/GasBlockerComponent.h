#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "Fixed.h"
#include "GasBlocker_Bool_EventDelegate.h"
#include "SimulationTimerComponent.h"
#include "GasBlockerComponent.generated.h"

class AGridObject;
class UDifficultySettingsSubsystem;
class UGasEmitterSimulationComponent;
class UInventoryComponent;
class UItemConfig;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGasBlockerComponent : public USimulationTimerComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGasBlocker_Bool_Event ActiveStateChangedEvent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGasEmitterSimulationComponent* GasEmitter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* Inventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference InventoryReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Slot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemConfig* ItemToAdd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed GasProductionInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsBlockingGas;
    
public:
    UGasBlockerComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnInventoryChanged(UInventoryComponent* InInventory, bool bAdded, UItemConfig* Item);
    
    UFUNCTION(BlueprintCallable)
    void OnGridPositionUnderneathChanged(AGridObject* GridObject, FIntPoint GridPosition);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnDifficultySettingsChanged(UDifficultySettingsSubsystem* Subsystem);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBlockingPossible();
    
};

