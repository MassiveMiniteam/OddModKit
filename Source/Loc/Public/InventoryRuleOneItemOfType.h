#pragma once
#include "CoreMinimal.h"
#include "InventoryRule_SlotSpecific.h"
#include "Templates/SubclassOf.h"
#include "InventoryRuleOneItemOfType.generated.h"

class UItemConfig;

UCLASS(Blueprintable)
class LOC_API UInventoryRuleOneItemOfType : public UInventoryRule_SlotSpecific {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemConfig>> ItemConfigTypes;
    
public:
    UInventoryRuleOneItemOfType();

};

