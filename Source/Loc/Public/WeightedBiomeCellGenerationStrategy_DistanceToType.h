#pragma once
#include "CoreMinimal.h"
#include "WeightedBiomeCellGenerationStrategy.h"
#include "WeightedBiomeCellGenerationStrategy_DistanceToType.generated.h"

class UBiomeCellConfig;

UCLASS(Blueprintable, EditInlineNew)
class UWeightedBiomeCellGenerationStrategy_DistanceToType : public UWeightedBiomeCellGenerationStrategy {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFarthest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBiomeCellConfig* CellType;
    
public:
    UWeightedBiomeCellGenerationStrategy_DistanceToType();

};

