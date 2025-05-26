#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "EDestructionReason.h"
#include "Fixed.h"
#include "ControlledMinionChangedEventDelegate.h"
#include "ItemStack.h"
#include "MinionConfigTagPair.h"
#include "MinionControlGroup.h"
#include "OnMinionControllerEventDelegate.h"
#include "ProjectileParameters.h"
#include "SimulationTimerComponent.h"
#include "MinionControllerSimulationBaseComponent.generated.h"

class ASimulationActor;
class ASimulationManager;
class UAchievement_BasicCount;
class UAchievement_MinionCount;
class UBTStateMachineComponent;
class UControllableMinionSimulationComponent;
class UEventDataAssetWithState;
class UInventoryComponent;
class UItemConfig;
class UItemMinionConfig;
class UPositionSimulationComponent;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UMinionControllerSimulationBaseComponent : public USimulationTimerComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FControlledMinionChangedEvent OnMinionAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FControlledMinionChangedEvent OnMinionRemoved;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMinionControllerEvent OnThrowableMinionAmountChangedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMinionControllerEvent OnMinionControllerChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMinionControllerEvent OnSpawnAllMinionExecuted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMinionControllerEvent OnDespawnAllMinionsExecuted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMinionControllerEvent OnMinionInventoryChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEventDataAssetWithState* OnLoadOutSwapProgressChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMinionControllerEvent OnIsLoadOutSwapPossibleChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInventoryComponent> MinionInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bEnableUnitSpawning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisablePushback;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRespawnOnRelocate;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FMinionControlGroup> ControlGroups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference MinionInventoryComponentReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DeployMinionsDirectlyOnInventorySlotChange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowTakeoverByOtherMinionController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag StateGroupAfterSpawning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag StateGroupAfterBeingThrown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag OwnerBrand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntVector SpawnPositionOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAchievement_MinionCount*> OnThrowAchievements_MinionCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAchievement_BasicCount*> OnThrowAchievements_BasicCount;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsLoadOutSwapPossible;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInventoryComponent> RequestedLoadoutInventory;
    
public:
    UMinionControllerSimulationBaseComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void UnregisterToMinionDelegates(ASimulationActor* Minion);
    
public:
    UFUNCTION(BlueprintCallable)
    bool TryAddAlreadySpawnedMinion(ASimulationActor* Minion);
    
private:
    UFUNCTION(BlueprintCallable)
    void TriggerLoadOutSwap();
    
public:
    UFUNCTION(BlueprintCallable)
    void ThrowMinion(ASimulationActor* Minion, FProjectileParameters ThrowProperties);
    
    UFUNCTION(BlueprintCallable)
    void SpawnUnitsByClass(UItemMinionConfig* Config, int32 AmountToBeSpawned, ASimulationManager* SimulationManager);
    
    UFUNCTION(BlueprintCallable)
    void SpawnUnits(const FMinionControlGroup& ControlGroup, int32 AmountToBeSpawned, ASimulationManager* SimulationManager);
    
    UFUNCTION(BlueprintCallable)
    void SpawnAllNotSpawnedUnits();
    
    UFUNCTION(BlueprintCallable)
    void RequestLoadOutSwap(UInventoryComponent* LoadOut);
    
    UFUNCTION(BlueprintCallable)
    void RemoveMinion(ASimulationActor* Minion);
    
private:
    UFUNCTION(BlueprintCallable)
    void RegisterToMinionDelegates(ASimulationActor* Minion);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnUnitSpawned(ASimulationActor* Minion);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSimulationActorShutDown(ASimulationActor* Minion, EDestructionReason Reason);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnRelocated(UPositionSimulationComponent* PositionComponent, FIntPoint LastGridPosition);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnMinionStateGroupChanged(UBTStateMachineComponent* StateMachine, FGameplayTag StateGroupTag);
    
    UFUNCTION(BlueprintCallable)
    void OnMinionStatDead(UStatsComponent* StatsComponent);
    
    UFUNCTION(BlueprintCallable)
    void OnMinionStatChanged(UStatsComponent* StatsComponent, FGameplayTag Tag, FFixed OldValue, FFixed NewValue);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnMinionInventoryUpdated(int32 InventorySlotIndex);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnControlGroupTagChanged(UControllableMinionSimulationComponent* ControllableMinionComponent);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLoadOutSwapPossible() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLoadOutSwapInProgress() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumSlots() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemMinionConfig* GetMinionConfig(int32 MinionSlotIndex) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryComponent* GetLoadOutSwapToInventory() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASimulationActor*> GetDeployedMinionsForTagPair(FMinionConfigTagPair ConfigTagPair);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    int32 GetDeployedMinionCountInTaggedGroups(UItemConfig* Config) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetDeployedMinionCount(int32 MinionSlotIndex) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetControlGroupIndex(FMinionConfigTagPair MinionConfigTagPair);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    ASimulationActor* GetClosestControlledMinion(const FIntVector& QueryPosition) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<ASimulationActor*> GetAllDeployedMinionsWithStat(FGameplayTag StatTag) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<ASimulationActor*> GetAllDeployedMinionsWithoutGroupTag() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<ASimulationActor*> GetAllDeployedMinions() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryComponent* GetActiveLoadOutInventory() const;
    
    UFUNCTION(BlueprintCallable)
    void DespawnUnits(const FMinionControlGroup& ControlGroup, int32 AmountToBeDespawned, ASimulationManager* SimulationManager);
    
    UFUNCTION(BlueprintCallable)
    void DespawnAllUnits();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FItemStack> ComputeDifferenceOfMinionsInControlGroupsAndInventory() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AllowsTakeoverByOtherMinionController() const;
    
    UFUNCTION(BlueprintCallable)
    void AddMinion(ASimulationActor* Minion);
    
};

