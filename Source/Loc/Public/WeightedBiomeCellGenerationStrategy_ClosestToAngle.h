#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "Fixed64.h"
#include "WeightedBiomeCellGenerationStrategy.h"
#include "WeightedBiomeCellGenerationStrategy_ClosestToAngle.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UWeightedBiomeCellGenerationStrategy_ClosestToAngle : public UWeightedBiomeCellGenerationStrategy {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed MinAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed MaxAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAbs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTryDiscardCellIfEdgeIsSmallerThan;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64 EdgeSmallerThan;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFromStartingCell;
    
public:
    UWeightedBiomeCellGenerationStrategy_ClosestToAngle();

};

