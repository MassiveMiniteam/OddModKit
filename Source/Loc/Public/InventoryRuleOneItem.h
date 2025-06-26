#pragma once
#include "CoreMinimal.h"
#include "InventoryRule_SlotSpecific.h"
#include "InventoryRuleOneItem.generated.h"

UCLASS(Blueprintable)
class LOC_API UInventoryRuleOneItem : public UInventoryRule_SlotSpecific {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOneItemPerSlot;
    
public:
    UInventoryRuleOneItem();

};

