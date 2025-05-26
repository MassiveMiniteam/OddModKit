#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProceduralGeneratorCondition.h"
#include "ProceduralGeneratorCondition_DistanceToCell.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UProceduralGeneratorCondition_DistanceToCell : public UProceduralGeneratorCondition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProceduralGeneratorCondition* ConditionForStartCellConfig;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntVector2 Distance;
    
public:
    UProceduralGeneratorCondition_DistanceToCell();

};

