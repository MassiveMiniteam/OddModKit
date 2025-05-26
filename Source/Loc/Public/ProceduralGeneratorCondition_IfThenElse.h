#pragma once
#include "CoreMinimal.h"
#include "ProceduralGeneratorCondition.h"
#include "ProceduralGeneratorCondition_IfThenElse.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UProceduralGeneratorCondition_IfThenElse : public UProceduralGeneratorCondition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProceduralGeneratorCondition* If;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProceduralGeneratorCondition* Then;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProceduralGeneratorCondition* Else;
    
public:
    UProceduralGeneratorCondition_IfThenElse();

};

