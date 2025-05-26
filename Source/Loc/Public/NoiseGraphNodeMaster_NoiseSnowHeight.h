#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NoiseGraphNodeMaster_NoiseSpawnBase.h"
#include "NoiseGraphNodeMaster_NoiseSnowHeight.generated.h"

class UGroundMeshMappingAsset;

UCLASS(Blueprintable)
class LOC_API UNoiseGraphNodeMaster_NoiseSnowHeight : public UNoiseGraphNodeMaster_NoiseSpawnBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGroundMeshMappingAsset* GroundMeshMappingAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowCliffs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint HeightRange;
    
    UNoiseGraphNodeMaster_NoiseSnowHeight();

};

