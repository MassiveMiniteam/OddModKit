#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NoiseGraphNodeMaster_NoiseSpawnBase.h"
#include "NoiseGraphNodeMaster_NoiseSpawnObject.generated.h"

class AActor;
class UGridTileLandscapeLayer;

UCLASS(Blueprintable)
class LOC_API UNoiseGraphNodeMaster_NoiseSpawnObject : public UNoiseGraphNodeMaster_NoiseSpawnBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRandomRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FreeSpaceNeededRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReduceChanceInFlatSeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ReduceChanceToInFlatSeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint HeightRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint CellDistanceToStartRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> ActorsToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDistributeLandscapeLayerUnderneath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileLandscapeLayer* LandscapeLayerToDistribute;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowSpawnOnDifferentHeights;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowCustomLandscapeLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowCliff;
    
public:
    UNoiseGraphNodeMaster_NoiseSpawnObject();
    virtual TArray<FString> GetInputs() const override
    {
        return { TEXT("A") };
    }

};

