#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "GlobalItemPickupTracker_Item_Amount_EventDelegate.h"
#include "GlobalItemPickupTracker.generated.h"

class ASimulationPlayer;
class UGlobalItemPickupTracker;
class UInventoryComponent;
class UItemConfig;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGlobalItemPickupTracker : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalItemPickupTracker_Item_Amount_Event OnItemPickedUp_Static;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<TSoftObjectPtr<UItemConfig>, int32> ItemConfigToAmount;
    
public:
    UGlobalItemPickupTracker(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnPickedUpItem(ASimulationPlayer* Player, UInventoryComponent* InventoryComponent, UItemConfig* Item, int32 Amount);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasEverPickedUpItemOfType(UItemConfig* ItemConfig);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static UGlobalItemPickupTracker* GetGlobalItemPickupTracker(const UObject* WorldContext);
    
};

