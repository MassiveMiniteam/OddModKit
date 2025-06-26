#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InventoryRule.h"
#include "InventoryRule_MatchingTags.generated.h"

UCLASS(Blueprintable)
class LOC_API UInventoryRule_MatchingTags : public UInventoryRule {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer RequiredTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ForbiddenTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheckExact;
    
public:
    UInventoryRule_MatchingTags();

};

