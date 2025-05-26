#pragma once
#include "CoreMinimal.h"
#include "InventoryRule_SlotSpecific.h"
#include "InventoryRuleOneItemOfConfig.generated.h"

class UItemConfig;

UCLASS(Blueprintable)
class LOC_API UInventoryRuleOneItemOfConfig : public UInventoryRule_SlotSpecific {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UItemConfig*> ItemConfigs;
    
    UInventoryRuleOneItemOfConfig();

};

