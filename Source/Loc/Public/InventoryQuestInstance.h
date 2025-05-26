#pragma once
#include "CoreMinimal.h"
#include "InventoryQuestInstanceEventDelegate.h"
#include "QuestInstance.h"
#include "InventoryQuestInstance.generated.h"

class UInventoryComponent;
class UInventoryRuleOneItemOfConfig;
class UItemConfig;

UCLASS(Blueprintable)
class LOC_API AInventoryQuestInstance : public AQuestInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryQuestInstanceEvent OnQuestInstanceInventoryChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* QuestInstanceInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInventoryRuleOneItemOfConfig*> AllowItemRules;
    
public:
    AInventoryQuestInstance(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnInventoryChanged(UInventoryComponent* Inventory, bool bAdded, UItemConfig* Item);
    
};

