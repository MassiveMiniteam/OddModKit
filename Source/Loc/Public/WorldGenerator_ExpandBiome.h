#pragma once
#include "CoreMinimal.h"
#include "ProceduralWorldGenerator.h"
#include "WorldGenerator_ExpandBiome.generated.h"

class UBiomeConfig;
class UProceduralGeneratorCondition;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UWorldGenerator_ExpandBiome : public UProceduralWorldGenerator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Comment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBiomeConfig* BiomeConfigToExpand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ExpandBy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProceduralGeneratorCondition* Condition;
    
    UWorldGenerator_ExpandBiome();

};

