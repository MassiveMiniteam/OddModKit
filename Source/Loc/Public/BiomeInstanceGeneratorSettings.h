#pragma once
#include "CoreMinimal.h"
#include "BiomeInstanceGeneratorSettings.generated.h"

class UBiomeCellInstance;
class UWorldGenerator;

USTRUCT(BlueprintType)
struct FBiomeInstanceGeneratorSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GeneratorSeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UBiomeCellInstance> BiomeCellInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorldGenerator* WorldGenerator;
    
    LOC_API FBiomeInstanceGeneratorSettings();
};

