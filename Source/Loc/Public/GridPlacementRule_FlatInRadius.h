#pragma once
#include "CoreMinimal.h"
#include "GridPlacementRuleConfig.h"
#include "GridPlacementRule_FlatInRadius.generated.h"

UCLASS(Blueprintable)
class LOC_API UGridPlacementRule_FlatInRadius : public UGridPlacementRuleConfig {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Radius;
    
public:
    UGridPlacementRule_FlatInRadius();

};

