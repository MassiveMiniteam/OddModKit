#pragma once
#include "CoreMinimal.h"
#include "InventoryRule.h"
#include "InventoryRule_SlotSpecific.generated.h"

UCLASS(Blueprintable)
class LOC_API UInventoryRule_SlotSpecific : public UInventoryRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TargetSlot;
    
    UInventoryRule_SlotSpecific();

};

