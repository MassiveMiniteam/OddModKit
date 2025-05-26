#pragma once
#include "CoreMinimal.h"
#include "GridPlacementRuleConfig.h"
#include "GridPlacementRule_DoNotDestroyPathsOnPlacing.generated.h"

UCLASS(Blueprintable)
class LOC_API UGridPlacementRule_DoNotDestroyPathsOnPlacing : public UGridPlacementRuleConfig {
    GENERATED_BODY()
public:
    UGridPlacementRule_DoNotDestroyPathsOnPlacing();

};

