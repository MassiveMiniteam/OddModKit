#pragma once
#include "CoreMinimal.h"
#include "InventoryRule_SlotSpecific.h"
#include "Templates/SubclassOf.h"
#include "InventoryRuleItemOfType.generated.h"

class UItemConfig;

UCLASS(Blueprintable)
class LOC_API UInventoryRuleItemOfType : public UInventoryRule_SlotSpecific {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemConfig>> ItemConfigTypes;
    
public:
    UInventoryRuleItemOfType();

};

