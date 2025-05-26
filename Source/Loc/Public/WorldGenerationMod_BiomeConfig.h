#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WorldGenerationMod_BiomeConfig.generated.h"

class UProceduralWorldGenerator;

UCLASS(Blueprintable)
class LOC_API UWorldGenerationMod_BiomeConfig : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TargetSortIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProceduralWorldGenerator* Generator;
    
    UWorldGenerationMod_BiomeConfig();

};

