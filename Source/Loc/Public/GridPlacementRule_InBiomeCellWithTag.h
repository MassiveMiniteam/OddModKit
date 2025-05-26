#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GridPlacementRuleConfig.h"
#include "GridPlacementRule_InBiomeCellWithTag.generated.h"

UCLASS(Blueprintable)
class LOC_API UGridPlacementRule_InBiomeCellWithTag : public UGridPlacementRuleConfig {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInverseCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag BiomeCellTag;
    
public:
    UGridPlacementRule_InBiomeCellWithTag();

};

