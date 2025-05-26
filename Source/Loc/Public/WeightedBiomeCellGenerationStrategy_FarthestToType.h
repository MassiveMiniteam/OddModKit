#pragma once
#include "CoreMinimal.h"
#include "WeightedBiomeCellGenerationStrategy.h"
#include "WeightedBiomeCellGenerationStrategy_FarthestToType.generated.h"

class UBiomeCellConfig;

UCLASS(Blueprintable, EditInlineNew)
class UWeightedBiomeCellGenerationStrategy_FarthestToType : public UWeightedBiomeCellGenerationStrategy {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBiomeCellConfig* CellType;
    
public:
    UWeightedBiomeCellGenerationStrategy_FarthestToType();

};

