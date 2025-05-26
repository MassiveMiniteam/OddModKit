#pragma once
#include "CoreMinimal.h"
#include "InventoryRule_SlotSpecific.h"
#include "InventoryRuleDisallowItem.generated.h"

class UItemConfig;

UCLASS(Blueprintable)
class LOC_API UInventoryRuleDisallowItem : public UInventoryRule_SlotSpecific {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UItemConfig*> ItemConfigs;
    
    UInventoryRuleDisallowItem();

};

