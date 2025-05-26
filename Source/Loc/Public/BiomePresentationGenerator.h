#pragma once
#include "CoreMinimal.h"
#include "CellPresentationGenerator.h"
#include "BiomePresentationGenerator.generated.h"

class UBiomeCellInstance;

UCLASS(Blueprintable)
class LOC_API UBiomePresentationGenerator : public UCellPresentationGenerator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBiomeCellInstance* BiomeCellInstance;
    
public:
    UBiomePresentationGenerator();

};

