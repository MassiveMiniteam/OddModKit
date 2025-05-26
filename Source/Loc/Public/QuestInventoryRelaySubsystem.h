#pragma once
#include "CoreMinimal.h"
#include "LocSimulationSubsystem.h"
#include "ItemStack.h"
#include "QuestInventoryRelaySubsystem_InventoryRelay_EventDelegate.h"
#include "QuestInventoryRelaySubsystem_QuestGiver_EventDelegate.h"
#include "QuestInventoryRelaySubsystem.generated.h"

class ASimulationActor;
class UInventoryComponent;
class UItemConfig;
class UQuestGiverSimulationComponent;
class UQuestInventoryRelayComponent;

UCLASS(Blueprintable)
class LOC_API UQuestInventoryRelaySubsystem : public ULocSimulationSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestInventoryRelaySubsystem_InventoryRelay_Event OnInventoryRelayRegistered;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestInventoryRelaySubsystem_InventoryRelay_Event OnInventoryRelayUnregistered;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestInventoryRelaySubsystem_QuestGiver_Event OnInventoryForQuestGiverChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UQuestInventoryRelayComponent*> RegisteredQuestInventoryRelays;
    
public:
    UQuestInventoryRelaySubsystem();

    UFUNCTION(BlueprintCallable)
    bool TryConsumeItems(UQuestGiverSimulationComponent* QuestGiver, const TArray<FItemStack>& ItemsToConsume);
    
    UFUNCTION(BlueprintCallable)
    void OnInventoryChanged(UInventoryComponent* Inventory, bool bAdded, UItemConfig* Item);
    
    UFUNCTION(BlueprintCallable)
    int32 GetTotalItemCountForConfig(UQuestGiverSimulationComponent* QuestGiver, UItemConfig* Config);
    
    UFUNCTION(BlueprintCallable)
    TArray<UInventoryComponent*> GetInventoryRelaysForActor(ASimulationActor* SimulationActor);
    
    UFUNCTION(BlueprintCallable)
    bool CanConsumeItems(UQuestGiverSimulationComponent* QuestGiver, const TArray<FItemStack>& ItemsToConsume);
    
};

