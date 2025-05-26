#pragma once
#include "CoreMinimal.h"
#include "ProceduralGeneratorCondition.h"
#include "ProceduralGeneratorCondition_All.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UProceduralGeneratorCondition_All : public UProceduralGeneratorCondition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UProceduralGeneratorCondition*> Conditions;
    
public:
    UProceduralGeneratorCondition_All();

};

