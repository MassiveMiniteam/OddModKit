#pragma once
#include "CoreMinimal.h"
#include "GridPlacementRuleConfig.h"
#include "GridPlacementRule_FulfillsGridPairCondition.generated.h"

UCLASS(Blueprintable)
class LOC_API UGridPlacementRule_FulfillsGridPairCondition : public UGridPlacementRuleConfig {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinHeightDistance;
    
public:
    UGridPlacementRule_FulfillsGridPairCondition();

};

