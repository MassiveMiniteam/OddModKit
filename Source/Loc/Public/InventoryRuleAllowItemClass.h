#pragma once
#include "CoreMinimal.h"
#include "InventoryRule_SlotSpecific.h"
#include "Templates/SubclassOf.h"
#include "InventoryRuleAllowItemClass.generated.h"

class UItemConfig;

UCLASS(Blueprintable)
class LOC_API UInventoryRuleAllowItemClass : public UInventoryRule_SlotSpecific {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemConfig>> ItemClasses;
    
    UInventoryRuleAllowItemClass();

};

