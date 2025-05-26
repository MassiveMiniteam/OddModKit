#pragma once
#include "CoreMinimal.h"
#include "ProceduralGeneratorCondition.h"
#include "ProceduralGeneratorCondition_BiomeConfig.generated.h"

class UBiomeConfig;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UProceduralGeneratorCondition_BiomeConfig : public UProceduralGeneratorCondition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBiomeConfig*> BiomeConfigs;
    
public:
    UProceduralGeneratorCondition_BiomeConfig();

};

