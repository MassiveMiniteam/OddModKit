#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WorldGenerationMod_CellConfig.generated.h"

class UBiomeConfig;
class UProceduralCellGenerator;

UCLASS(Blueprintable)
class LOC_API UWorldGenerationMod_CellConfig : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBiomeConfig* TargetBiomeConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TargetSortIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProceduralCellGenerator* Generator;
    
    UWorldGenerationMod_CellConfig();

};

