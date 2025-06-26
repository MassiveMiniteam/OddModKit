#pragma once
#include "CoreMinimal.h"
#include "ConstructableConfig.h"
#include "ConstructableGroundTileConfig.generated.h"

class UGroundMeshMappingAsset;

UCLASS(Blueprintable)
class LOC_API UConstructableGroundTileConfig : public UConstructableConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UGroundMeshMappingAsset> GroundMesh;
    
    UConstructableGroundTileConfig();

};

