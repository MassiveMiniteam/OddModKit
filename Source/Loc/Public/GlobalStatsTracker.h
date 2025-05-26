#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "GlobalStatsTracker_InteractedWithSimulationActorEventDelegate.h"
#include "GlobalStatsTracker_WorkerSimulationComponent_Inventory_Item_EventDelegate.h"
#include "GlobalsStatsTracker_GridObject_Int_EventDelegate.h"
#include "OnGlobalStatsTrackerEventDelegate.h"
#include "OnGlobalStatsTrackerRecipeCraftedEventDelegate.h"
#include "OnGlobalStatsTrackerRecipeProgressEventDelegate.h"
#include "OnGlobalStatsTrackerSimulationActorEventDelegate.h"
#include "OnGlobalStatsTrackerWorkerMinionAssignedDelegate.h"
#include "OnGlobalStatsTracker_Integer_ActorType_EventDelegate.h"
#include "OnGlobalStatsTracker_MinionController_Integer_EventDelegate.h"
#include "Templates/SubclassOf.h"
#include "GlobalStatsTracker.generated.h"

class AActor;
class AGridObject;
class ASimulationActor;
class UGlobalStatsTracker;
class UMinionControllerSimulationBaseComponent;
class UObject;
class UTemperatureReceiverSimulationComponent;
class UUnlockableDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGlobalStatsTracker : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGlobalStatsTrackerSimulationActorEvent SimulationActorDiedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGlobalStatsTrackerRecipeCraftedEvent OnRecipeCrafted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGlobalStatsTrackerWorkerMinionAssigned OnWorkerAssigned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGlobalStatsTrackerRecipeProgressEvent OnRecipeProcessorProgressChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalsStatsTracker_GridObject_Int_Event OnGridObjectBuilt;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGlobalStatsTracker_MinionController_Integer_Event OnMinionNumberOfThrownMinionsChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGlobalStatsTracker_Integer_ActorType_Event OnNumberOfCalledBackMinionsChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalStatsTracker_WorkerSimulationComponent_Inventory_Item_Event OnWorkerTransportedItemToInventory;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalStatsTracker_InteractedWithSimulationActorEvent OnTrackedNewInteractable;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGlobalStatsTrackerEvent OnReservedChargesChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<UMinionControllerSimulationBaseComponent*, int32> ThrownMinionsCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 AssignedWorkersCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ManuallyCraftedItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ReservedPrinterCharges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<AActor>, int32> CalledBackMinionCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<AGridObject>, int32> BuiltConstructables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<ASimulationActor>, int32> SimulationActorToInteractionCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUnlockableDataAsset* Unlockable_TemperatureAffectedAnyWorkstation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUnlockableDataAsset* Unlockable_HostilityAffectedAnyWorkstation;
    
public:
    UGlobalStatsTracker(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void ReserveCharge();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnTemperatureEfficiencyChangedGlobalEvent(UTemperatureReceiverSimulationComponent* TemperatureReceiverSimulationComponent, FFixed Temperature);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetReservedCharges() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static UGlobalStatsTracker* GetGlobalStatsTracker(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable)
    void FreeCharge();
    
    UFUNCTION(BlueprintCallable)
    void AddCalledBackMinion(UMinionControllerSimulationBaseComponent* MinionController, TSubclassOf<AActor> MinionType);
    
};

