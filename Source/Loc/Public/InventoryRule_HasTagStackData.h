#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InventoryRule.h"
#include "InventoryRule_HasTagStackData.generated.h"

UCLASS(Blueprintable)
class LOC_API UInventoryRule_HasTagStackData : public UInventoryRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer RequiredTags;
    
    UInventoryRule_HasTagStackData();

};

