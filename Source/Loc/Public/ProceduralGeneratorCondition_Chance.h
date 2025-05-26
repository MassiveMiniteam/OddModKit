#pragma once
#include "CoreMinimal.h"
#include "ProceduralGeneratorCondition.h"
#include "ProceduralGeneratorCondition_Chance.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UProceduralGeneratorCondition_Chance : public UProceduralGeneratorCondition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ChancePercent;
    
public:
    UProceduralGeneratorCondition_Chance();

};

