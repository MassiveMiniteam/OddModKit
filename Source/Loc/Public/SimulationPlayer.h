#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "LocPlayerId.h"
#include "SimulationActor.h"
#include "SimulationPlayerEventDelegate.h"
#include "SimulationPlayer.generated.h"

class UInventoryComponent;
class UItemConfig;
class UObject;

UCLASS(Blueprintable)
class LOC_API ASimulationPlayer : public ASimulationActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimulationPlayerEvent OnPlayerRevived;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FLocPlayerId OwnerId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* Inventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* MinionInventoryReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HotbarLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed HarvestRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* CursorInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* CursorCancelInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UObject> LastCursorOrigin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CursorCancelSlotIndex;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bPlayerIsOnline;
    
public:
    ASimulationPlayer(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void TryToAssignCharacterPresentation();
    
    UFUNCTION(BlueprintCallable)
    void ReviveSimulationPlayer();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnPickedUpItem(UItemConfig* Config, int32 Amount, UObject* Origin);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnCursorItemAdded(UItemConfig* Config, int32 Amount, UObject* Origin);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCameOnline();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayerOnline() const;
    
};

