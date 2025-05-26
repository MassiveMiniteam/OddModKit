#pragma once
#include "CoreMinimal.h"
#include "GridPlacementRuleConfig.h"
#include "GridPlacementRule_SurroundingTilesAllowBuilding.generated.h"

UCLASS(Blueprintable)
class LOC_API UGridPlacementRule_SurroundingTilesAllowBuilding : public UGridPlacementRuleConfig {
    GENERATED_BODY()
public:
    UGridPlacementRule_SurroundingTilesAllowBuilding();

};

