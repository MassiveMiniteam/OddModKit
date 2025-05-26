#pragma once
#include "CoreMinimal.h"
#include "InventoryRule.h"
#include "InventoryRuleGenericItemEntry.h"
#include "InventoryRuleAllowGeneric.generated.h"

UCLASS(Blueprintable)
class LOC_API UInventoryRuleAllowGeneric : public UInventoryRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInventoryRuleGenericItemEntry> GenericItems;
    
    UInventoryRuleAllowGeneric();

};

