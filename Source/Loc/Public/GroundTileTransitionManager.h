#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SimulationActor.h"
#include "GroundTransitionInstance.h"
#include "GroundTileTransitionManager.generated.h"

class UGridTileGroundLayer;
class UGridTileLandscapeLayer;
class UProceduralTerrainLoadStrategy;
class UProceduralTerrainLoadStrategy_LocalPlayer;
class UStableInstancedStaticMeshComponent;
class UStaticMesh;

UCLASS(Blueprintable)
class LOC_API AGroundTileTransitionManager : public ASimulationActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LoadSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DistanceForUpdate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UProceduralTerrainLoadStrategy* CurrentLoadStrategy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UProceduralTerrainLoadStrategy_LocalPlayer* LoadStrategy_AroundLocalPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* TransitionMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileLandscapeLayer* LakeLandscapeLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector MeshOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UGridTileGroundLayer*, int32> PrePoolTransitions;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<UGridTileGroundLayer*, UStableInstancedStaticMeshComponent*> InstancedMeshComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStableInstancedStaticMeshComponent*> ISMSToUpdateRenderState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint LastPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsFirstTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, FGroundTransitionInstance> SpawnedTransitionTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> Directions;
    
public:
    AGroundTileTransitionManager(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnGridCellMeshNeedsUpdate(FIntPoint GridPosition, bool bIsHeightChange);
    
public:
    UFUNCTION(BlueprintCallable)
    void ForceLoad();
    
};

