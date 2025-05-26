#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NoiseGraphNodeMaster_NoiseSpawnBase.h"
#include "NoiseSpawnGroundMeshGroundTypeItem.h"
#include "NoiseGraphNodeMaster_NoiseGroundMesh_GroundType.generated.h"

UCLASS(Blueprintable)
class LOC_API UNoiseGraphNodeMaster_NoiseGroundMesh_GroundType : public UNoiseGraphNodeMaster_NoiseSpawnBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint HeightRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNoiseSpawnGroundMeshGroundTypeItem> SpawnByGroundTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FreeSpaceNeededRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowCliff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint CellDistanceToStartRange;
    
public:
    UNoiseGraphNodeMaster_NoiseGroundMesh_GroundType();
    virtual TArray<FString> GetInputs() const override
    {
        return { TEXT("A") };
    }

};

