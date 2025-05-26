#pragma once
#include "CoreMinimal.h"
#include "InventoryRule.h"
#include "Templates/SubclassOf.h"
#include "InventoryRuleNoItemOfType.generated.h"

class UItemConfig;

UCLASS(Blueprintable)
class LOC_API UInventoryRuleNoItemOfType : public UInventoryRule {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemConfig>> ForbiddenItemConfigTypes;
    
public:
    UInventoryRuleNoItemOfType();

};

