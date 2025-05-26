#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GridPlacementRuleConfig.h"
#include "GridPlacementRule_NotOnTopOfSimActorsWithGameplayTag.generated.h"

UCLASS(Blueprintable)
class LOC_API UGridPlacementRule_NotOnTopOfSimActorsWithGameplayTag : public UGridPlacementRuleConfig {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInvertCondition;
    
public:
    UGridPlacementRule_NotOnTopOfSimActorsWithGameplayTag();

};

