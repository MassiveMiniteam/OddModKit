#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "ItemStack.h"
#include "LootDropTracker_LootDrop_EventDelegate.h"
#include "Templates/SubclassOf.h"
#include "TrackedLootData.h"
#include "LootDropTrackerSimulationComponent.generated.h"

class AActor;
class ASimulationActor;
class ULootDropSimulationComponent;
class ULootDropTrackerSimulationComponent;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULootDropTrackerSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLootDropTracker_LootDrop_Event OnLootDroppedDelegate;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<AActor>, FTrackedLootData> ActorTypeToTrackedLootData;
    
public:
    ULootDropTrackerSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void UnlockDropsFor(TSubclassOf<ASimulationActor> ActorClass);
    
    UFUNCTION(BlueprintCallable)
    void OnLootDropped(ULootDropSimulationComponent* LootDropComponent, FItemStack Item);
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static ULootDropTrackerSimulationComponent* GetLootDropTracker(UObject* WorldContext);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTrackedLootData GetLootDataForActorType(TSubclassOf<AActor> ActorClass);
    
};

