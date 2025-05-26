#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "GridTileLayerAsset.generated.h"

class UMaterialInstance;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class LOC_API UGridTileLayerAsset : public UPrimaryDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor MapColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDrawMapBlackOnHighLevels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HeightTreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 MapID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumCustomPrimitiveData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstance*> LandscapeMaterials;
    
    UGridTileLayerAsset();

    UFUNCTION(BlueprintCallable)
    void ApplyLandscapeMaterialToStaticMesh(UStaticMeshComponent* StaticMeshComponent);
    
};

