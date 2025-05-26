#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "ManPowerEventDelegate.h"
#include "ManpowerComponentEventDelegate.h"
#include "OnCraftingPlayerEventDelegate.h"
#include "WorkerSlot.h"
#include "ManpowerSimulationComponent.generated.h"

class ASimulationPlayer;
class UInventoryComponent;
class UItemConfig;
class ULogicConnectionSimulationComponent;
class UObject;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UManpowerSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FManPowerEvent OnWorkSlotChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FManpowerComponentEvent OnManpwerComponentUpdated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCraftingPlayerEvent OnCraftingPlayerAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCraftingPlayerEvent OnCraftingPlayerRemoved;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed BaseManpower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxAllowedCraftingPlayers;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<ASimulationPlayer>> CurrentlyCraftingPlayers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInventoryComponent> WorkerInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWorkerSlot> WorkerSlots;
    
public:
    UManpowerSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateManpower();
    
public:
    UFUNCTION(BlueprintCallable)
    void RemoveCraftingPlayer(ASimulationPlayer* Player);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnStatChanged(UStatsComponent* StatsComponentIn, FGameplayTag Tag, FFixed OldValue, FFixed NewValue);
    
    UFUNCTION(BlueprintCallable)
    void OnSlotChanged(int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnLogicInputChanged(ULogicConnectionSimulationComponent* Input);
    
    UFUNCTION(BlueprintCallable)
    void OnItemAdded(UItemConfig* Config, int32 Amount, UObject* Origin);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWorkerSlotEnabled(int32 Index) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWorkerSlotConnectedToLogic(int32 Index) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSlotReadyToWork(int32 SlotIndex) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumberOfWorkingSlots() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ULogicConnectionSimulationComponent* GetLogicConnectionForSlot(int32 Index) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASimulationPlayer*> GetCurrentlyCraftingPlayers();
    
    UFUNCTION(BlueprintCallable)
    void AddCraftingPlayer(ASimulationPlayer* Player);
    
};

