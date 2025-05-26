#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimulationActor.h"
#include "GridTileRule.h"
#include "ProceduralRampRotationAndHeight.h"
#include "TileLayerInstancedMeshes.h"
#include "ProceduralTerrainManager.generated.h"

class UDataTable;
class UGridTileLandscapeLayer;
class UProceduralTerrainLoadStrategy;
class UProceduralTerrainLoadStrategy_LocalPlayer;
class UProceduralTileMeshRenderer;
class UStaticMesh;

UCLASS(Blueprintable)
class LOC_API AProceduralTerrainManager : public ASimulationActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileLandscapeLayer* RampLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileLandscapeLayer* LakeLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> RampMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> RampMeshEdgeRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> RampMeshEdgeLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> LakeMeshNoCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, FTileLayerInstancedMeshes> GroundLayerMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, FTileLayerInstancedMeshes> PhysicsGroundLayerMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, FTileLayerInstancedMeshes> DiggableLayerMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, FTileLayerInstancedMeshes> PhysicsDiggableLayerMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, FTileLayerInstancedMeshes> LandscapeLayerMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint LastGridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGridTileRule> TileRules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGridTileRule> TileRulesDiggables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* GridTileRules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* GridTileRulesDiggables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FIntPoint> PositionsLastUpdate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FIntPoint> DiggablePositionsLastUpdate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FIntPoint> PositionsLastUpdatePhysics;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FIntPoint> DiggablePositionsLastUpdatePhysics;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FIntPoint> LandscapePositionsLastUpdate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FIntPoint> PositionsToUpdate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProceduralTileMeshRenderer* TileMeshRenderer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGridTileLandscapeLayer*> DiggableLayers;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, FProceduralRampRotationAndHeight> RampInstancesRotationsAndHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UProceduralTerrainLoadStrategy* CurrentLoadStrategy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UProceduralTerrainLoadStrategy* CurrentPhysicsLoadStrategy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UProceduralTerrainLoadStrategy* VillageLoadStrategy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UProceduralTerrainLoadStrategy* VillagePhysicsLoadStrategy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UProceduralTerrainLoadStrategy_LocalPlayer* LoadStrategy_AroundLocalPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UProceduralTerrainLoadStrategy_LocalPlayer* LoadStrategy_AroundLocalPlayer_Physics;
    
    AProceduralTerrainManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void OnGridCellMeshNeedsUpdate(FIntPoint GridPos, bool bIsHeightChange);
    
};

