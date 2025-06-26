#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "ItemStack.h"
#include "RecentlyUnlocked_DataAsset_EventDelegate.h"
#include "RecentlyUnlocked_EventDelegate.h"
#include "Templates/SubclassOf.h"
#include "RecentlyUnlockedAssetsTracker.generated.h"

class UDataAsset;
class UGlobalItemPickupTracker;
class UItemConfig;
class ULootDropSimulationComponent;
class ULootDropTrackerSimulationComponent;
class UObject;
class UProductEntitlementDataAsset;
class URecentlyUnlockedAssetsTracker;
class URecentlyUnlockedAssetsTrackerSimulationComponent;
class UUnlockHandlingSimulationComponent;
class UUnlockableDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API URecentlyUnlockedAssetsTracker : public UPresentationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRecentlyUnlocked_Event OnRecentlyUnlockedItemsListChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRecentlyUnlocked_DataAsset_Event OnRecentlyUnlockedDataAssetAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRecentlyUnlocked_DataAsset_Event OnMarkedDataAssetAsSeen;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUnlockHandlingSimulationComponent* UnlockHandler;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGlobalItemPickupTracker* GlobalItemPickupTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULootDropTrackerSimulationComponent* LootDropTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URecentlyUnlockedAssetsTrackerSimulationComponent* RecentlyUnlockedAssetTrackerSimulation;
    
public:
    URecentlyUnlockedAssetsTracker(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void RefreshEntitlementRecentlyUnlocked();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRecentlyUnlockedItemsListChanged_Event(URecentlyUnlockedAssetsTrackerSimulationComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    void OnRecentlyUnlockedDataAssetMarkedAsSeen_Event(URecentlyUnlockedAssetsTrackerSimulationComponent* Component, UDataAsset* DataAsset);
    
    UFUNCTION(BlueprintCallable)
    void OnRecentlyUnlockedDataAssetAdded_Event(URecentlyUnlockedAssetsTrackerSimulationComponent* Component, UDataAsset* DataAsset);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnLootDropped(ULootDropTrackerSimulationComponent* InLootDropTracker, FItemStack DroppedItemStack, ULootDropSimulationComponent* LootDropComponent);
    
    UFUNCTION(BlueprintCallable)
    void OnItemUnlocked(UUnlockableDataAsset* UnlockableDataAsset);
    
    UFUNCTION(BlueprintCallable)
    void OnItemPickedUp(UGlobalItemPickupTracker* ItemPickupTracker, UItemConfig* RecentlyPickedUpItem, int32 TotalAmount);
    
    UFUNCTION(BlueprintCallable)
    void OnEntitlementChanged(UProductEntitlementDataAsset* ProductEntitlementDataAsset);
    
public:
    UFUNCTION(BlueprintCallable)
    void MarkObjectAsSeen(UObject* SeenObject);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDataAssetRecentlyUnlocked(UObject* Object);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasRecentlyUnlockedDataAssetOfType(TArray<TSubclassOf<UDataAsset>> DataAssetTypes);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static URecentlyUnlockedAssetsTracker* GetRecentlyUnlockedAssetTracker(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable)
    void AddDataAsset(UDataAsset* InDataAsset);
    
};

