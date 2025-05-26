#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "ForestBiomeGeneratorAdditionalDecorationItem.generated.h"

class AGridObject;
class UGroundMeshMappingAsset;

USTRUCT(BlueprintType)
struct FForestBiomeGeneratorAdditionalDecorationItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AGridObject>> Actors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGroundMeshMappingAsset* GroundMeshMapping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed SpawnChancePerTile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed SpawnChanceReductionByDistance;
    
    LOC_API FForestBiomeGeneratorAdditionalDecorationItem();
};

