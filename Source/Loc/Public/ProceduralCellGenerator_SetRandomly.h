#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProceduralCellGenerator.h"
#include "ProceduralCellGenerator_SetRandomly.generated.h"

class UBiomeCellConfig;
class UProceduralGeneratorCondition;
class UWeightedBiomeCellGenerationStrategy;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UProceduralCellGenerator_SetRandomly : public UProceduralCellGenerator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Comment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBiomeCellConfig* CellConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDontOverrideCells;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint AmountRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWeightedBiomeCellGenerationStrategy* Strategy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProceduralGeneratorCondition* Condition;
    
    UProceduralCellGenerator_SetRandomly();

};

