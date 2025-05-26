#pragma once
#include "CoreMinimal.h"
#include "ProceduralGeneratorCondition.h"
#include "ProceduralGeneratorCondition_CellConfig.generated.h"

class UBiomeCellConfig;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UProceduralGeneratorCondition_CellConfig : public UProceduralGeneratorCondition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBiomeCellConfig* CellConfig;
    
public:
    UProceduralGeneratorCondition_CellConfig();

};

