#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BiomeGenerator.generated.h"

class UBiomeCellInstance;

UCLASS(Blueprintable)
class LOC_API UBiomeGenerator : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UBiomeCellInstance> BiomeCellInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GeneratorSeed;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BasePriority;
    
    UBiomeGenerator();

};

