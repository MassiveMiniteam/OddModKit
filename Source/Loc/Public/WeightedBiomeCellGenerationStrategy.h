#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WeightedBiomeCellGenerationStrategy.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UWeightedBiomeCellGenerationStrategy : public UObject {
    GENERATED_BODY()
public:
    UWeightedBiomeCellGenerationStrategy();

};

