#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EvolutionBudgetToVisualizationIndexTableData.generated.h"

USTRUCT(BlueprintType)
struct FEvolutionBudgetToVisualizationIndexTableData : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Threshold;
    
    LOC_API FEvolutionBudgetToVisualizationIndexTableData();
};

