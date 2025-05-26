#pragma once
#include "CoreMinimal.h"
#include "InventoryRule_SlotSpecific.h"
#include "InventoryRuleStackSizeMultiplier.generated.h"

class UItemConfig;

UCLASS(Blueprintable)
class LOC_API UInventoryRuleStackSizeMultiplier : public UInventoryRule_SlotSpecific {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Multiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UItemConfig*> DontAllowItemConfigs;
    
    UInventoryRuleStackSizeMultiplier();

};

