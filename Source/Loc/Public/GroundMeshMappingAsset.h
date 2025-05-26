#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CellISMConfig.h"
#include "GroundMeshMappingAsset.generated.h"

class UStaticMesh;

UCLASS(Blueprintable)
class LOC_API UGroundMeshMappingAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 SnowHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStaticMesh*> StaticMeshesRandom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCellISMConfig CellISMConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRandomRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseStableInstanceMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReceiveDecals;
    
    UGroundMeshMappingAsset();

};

