#pragma once
#include "CoreMinimal.h"
#include "WeightedBiomeCellGenerationStrategy.h"
#include "WeightedBiomeCellGenerationStrategy_MinEdgeAmount.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UWeightedBiomeCellGenerationStrategy_MinEdgeAmount : public UWeightedBiomeCellGenerationStrategy {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinEdgeAmount;
    
public:
    UWeightedBiomeCellGenerationStrategy_MinEdgeAmount();

};

