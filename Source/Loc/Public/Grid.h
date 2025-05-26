#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "Fixed64.h"
#include "CellMetaDataBlockGrid.h"
#include "CellMetaDataSpawnActor.h"
#include "ChunkPosition.h"
#include "GlobalGridCellChangedEventDelegate.h"
#include "GlobalGridCellMeshNeedsUpdateEventDelegate.h"
#include "GridObjectEventDelegate.h"
#include "IntVectorPair.h"
#include "SimulationActorConditionEventDelegate.h"
#include "WorldGenerationInfo.h"
#include "Grid.generated.h"

class AGridObject;
class ASimulationActor;
class UBiomeCellConfig;
class UBiomeCellInstance;
class UChunkManager;
class UGridTileGroundLayer;
class UGridTileLandscapeLayer;
class UWorldGenerationConfig;
class UWorldGenerator;
class UWorldMapDataComponent;

UCLASS(Blueprintable)
class LOC_API AGrid : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AGridObject*> EmptyGridObjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASimulationActor*> EmptySimulationActors;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Seed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ChunkSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorldGenerationConfig* WorldGenerationConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UChunkManager* ChunkManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorldGenerator* WorldGenerator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWorldMapDataComponent* WorldMapDataComponent;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalGridCellChangedEvent OnGridCellChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGridObjectEvent OnGridObjectRegistered;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGridObjectEvent OnGridObjectUnregistered;
    
    UPROPERTY(BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalGridCellMeshNeedsUpdateEvent OnGridCellMeshNeedsUpdate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, FCellMetaDataSpawnActor> CellMetaSpawnActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UClass*> GeneratedSpawnedActorClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, FCellMetaDataBlockGrid> CellMetaBlockGrid;
    
    AGrid(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntVector SnapToGrid(FIntVector CenterPosition, FIntPoint SizeInTiles, int32 Rotation) const;
    
    UFUNCTION(BlueprintCallable)
    bool SetupGeneration(int32 InSeed, bool bIsLoading, FWorldGenerationInfo& InOutWorldGenerationInfo);
    
    UFUNCTION(BlueprintCallable)
    void Setup(int32 InSeed, bool bIsLoading, FWorldGenerationInfo& InOutWorldGenerationInfo, bool bRerollInvalidSeed);
    
    UFUNCTION(BlueprintCallable)
    void SetGridTileSnowHeight(FIntPoint GridPosition, uint8 SnowHeight);
    
    UFUNCTION(BlueprintCallable)
    void SetGridTileLandscapeLayer(FIntPoint GridPosition, UGridTileLandscapeLayer* Layer);
    
    UFUNCTION(BlueprintCallable)
    void SetGridTileGroundLayer(FIntPoint GridPosition, UGridTileGroundLayer* Layer);
    
    UFUNCTION(BlueprintCallable)
    void RemoveSimulationActorToCell(FIntPoint position, ASimulationActor* SimulationActor);
    
    UFUNCTION(BlueprintCallable)
    void RemoveGridObjectToCells(AGridObject* GridObject, const TArray<FIntPoint>& Positions);
    
    UFUNCTION(BlueprintCallable)
    void RemoveGridObjectToCell(FIntPoint position, AGridObject* GridObject);
    
    UFUNCTION(BlueprintCallable)
    void NotifyGridCellMeshNeedsUpdateAround(FIntPoint GridPosition, int32 Radius);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsValidGridPosition(FIntPoint position) const;
    
    UFUNCTION(BlueprintCallable)
    bool IsValidGridIndex(int32 Index) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTileWalkable(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable)
    bool IsSimulationSphereCastIntersectedByLandscapeHeight(const FIntVector& Target, const FIntVector& Origin, int32 AllowedHeight, int32 Radius);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRampCornerOrCliff(const FIntPoint& GridPosition);
    
    UFUNCTION(BlueprintCallable)
    bool IsRampCornerAtPosition(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRampAtPosition(FIntPoint GridPosition, bool bAlsoConsiderConstructableRamps);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPositionInsideCone(const FIntVector& ConeCenter, const FIntVector& ConeCenterDirection, const FFixed& ConeAngle, const FIntVector& TestLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCliffCorner(const FIntPoint& GridPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCliffAtPositionWithMaxHeight(const FIntPoint& GridPosition, int32 Height);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCliffAtPositionWithCliffHeight(const FIntPoint& GridPosition, int32 CliffHeight);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCliffAtPositionIncludingDiagonals(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCliffAtPosition(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable)
    bool IsActorWithTagBetweenLocations(const FGameplayTag& Tag, const FIntVector& Target, const FIntVector& Origin, int32 LineThickness, TArray<AGridObject*>& OutIntersectingGridObjects);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntVector GetWorldPosition(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetWorldHeightAtWorldPosition(FIntVector WorldPosition);
    
    UFUNCTION(BlueprintCallable)
    int32 GetWorldHeightAtGridPosition(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntPoint GetWestVector();
    
    UFUNCTION(BlueprintCallable)
    TArray<FIntPoint> GetTilesSimulationSphereTrace(const FIntVector& Target, const FIntVector& Origin, int32 Radius);
    
    UFUNCTION(BlueprintCallable)
    TArray<FIntPoint> GetTilesInLine(const FIntVector& Target, const FIntVector& Origin, int32 LineThickness);
    
    UFUNCTION(BlueprintCallable)
    FIntVector GetTerrainNormalAt(const FIntPoint& GridPosition, FIntPoint& OutNeighbourGridPosition);
    
    UFUNCTION(BlueprintCallable)
    TArray<FIntPoint> GetSphereTraceAlongPath(const TArray<FIntVector>& TrackedPath, int32 Radius);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntPoint GetSouthWestVector();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntPoint GetSouthVector();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntPoint GetSouthEastVector();
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<ASimulationActor*> GetSimulationActorsWithinWorldDistanceAndInArc(const FSimulationActorConditionEvent& Condition, const FIntVector& WorldPosition, int32 DistanceInWorldUnits, const FIntVector& LookAtPosition, FFixed ArcAngle) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<ASimulationActor*> GetSimulationActorsWithinWorldDistance(const FIntVector& WorldPosition, int32 DistanceInWorldUnits) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<ASimulationActor*> GetSimulationActorsWithinTileDistance(const FIntPoint& GridCoordinates, int32 DistanceInGridUnits) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASimulationActor*> GetSimulationActorsAt(const FIntPoint& position) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<ASimulationActor*> GetSimulationActorsAndGridObjectsWithinWorldDistanceAndInArc(const FIntVector& WorldPosition, int32 DistanceInWorldUnits, FFixed ConeCenterLineRotation, FFixed ArcAngle) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASimulationActor*> GetSimulationActorsAndGridObjectsAt(const FIntPoint& position) const;
    
    UFUNCTION(BlueprintCallable)
    bool GetRampDirection(FIntPoint GridPosition, FIntPoint& DirectionOut, bool& bIsTopPart);
    
    UFUNCTION(BlueprintCallable)
    FIntPoint GetPositionForIndex(int32 Index) const;
    
    UFUNCTION(BlueprintCallable)
    TMap<UBiomeCellInstance*, int32> GetOverlappingBiomeCellInstanceCounts(FIntPoint Origin);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntPoint GetNorthWestVector();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntPoint GetNorthVector();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntPoint GetNorthEastVector();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FIntPoint> GetNeighbours(FIntPoint Origin, bool bIncludeDiagonal) const;
    
    UFUNCTION(BlueprintCallable)
    UBiomeCellInstance* GetMostOverlappingBiomeCell(FIntPoint Origin);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsFlatSeed() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetIsBuildableArea(const FIntPoint& GridPosition);
    
    UFUNCTION(BlueprintCallable)
    int32 GetIndexForPosition(FIntPoint position) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetHeightAtGridPosition(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable)
    uint8 GetGridTileSnowHeight(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable)
    UGridTileLandscapeLayer* GetGridTileLandscapeLayer(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable)
    UGridTileGroundLayer* GetGridTileGroundLayer(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<AGridObject*> GetGridObjectsWithinWorldDistance(const FIntVector& WorldPosition, int32 DistanceInWorldUnits) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<AGridObject*> GetGridObjectsWithinTileDistance(const FIntPoint& GridCoordinates, int32 DistanceInGridUnits) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AGridObject*> GetGridObjectsAt(const FIntPoint& position) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<ASimulationActor*> GetGridObjectsAndSimulationActorsWithinWorldDistance(const FIntVector& WorldPosition, int32 DistanceInWorldUnits) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetGeneratedHeightAt(int32 X, int32 Y);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntPoint GetEastVector();
    
    UFUNCTION(BlueprintCallable)
    int32 GetCountForBiomeCellInstanceAroundOrigin(FIntPoint Origin, UBiomeCellInstance* BiomeCellInstanceToCheck);
    
    UFUNCTION(BlueprintCallable)
    int32 GetCountForBiomeCellConfigAroundOrigin(FIntPoint Origin, UBiomeCellConfig* BiomeCellConfig);
    
    UFUNCTION(BlueprintCallable)
    FIntVector GetClosestWalkablePositionFromAnotherPosition(const FIntVector& TargetPosition, const FIntVector& RequesterPosition, int32 MaxRadiusInWorldUnits);
    
    UFUNCTION(BlueprintCallable)
    FIntVector GetClosestWalkablePosition(const FIntVector& position);
    
    UFUNCTION(BlueprintCallable)
    FIntPoint GetClosestFreeCellExcluding(FIntPoint InGridCoordinates, bool& bSuccess, TArray<FIntPoint> ExcludingTiles, int32 MaxSize);
    
    UFUNCTION(BlueprintCallable)
    FIntPoint GetClosestFreeCell(FIntPoint InGridCoordinates, bool& bSuccess, int32 MaxSize);
    
    UFUNCTION(BlueprintCallable)
    int32 GetCliffHeightAtGridPosition(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable)
    void GetChunkCornerPositions(FChunkPosition ChunkPosition, FVector& LeftTop, FVector& RightTop, FVector& LeftBottom, FVector& RightBottom);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FIntPoint> GetCellsForArea(FIntVector CenterPosition, FIntPoint Area, int32 RotationOffset);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UBiomeCellInstance* GetBiomeCellAt(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FIntPoint> GetAllGridCoordinatesInRing(int32 MinRadius, int32 MaxRadius, const FIntPoint& BaseCoordinates);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FIntPoint> GetAllGridCoordinatesInRadiusWordLocation(const FIntVector& WorldLocation, FFixed64 Radius);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FIntPoint> GetAllGridCoordinatesInRadius(int32 Radius, const FIntPoint& BaseCoordinates);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FIntPoint> GetAllGridCoordinatesInCone(FFixed MinRadius, FFixed MaxRadius, FIntPoint BaseCoordinates, FIntPoint TargetCoordinates, FFixed Angle);
    
    UFUNCTION(BlueprintCallable)
    TArray<FChunkPosition> GetAllChunkPositionsInRadius(int32 ChunkRadius, const FIntPoint& BaseCoordinates);
    
    UFUNCTION(BlueprintCallable)
    TArray<FIntVectorPair> GetAllCellBordersInRadius(int32 CellRadiusInChunks, const FIntPoint& BaseCoordinates);
    
    UFUNCTION(BlueprintCallable)
    bool FindClosestCliff(FIntPoint QueryPosition, int32 QueryRange, FIntPoint& CliffPosition);
    
    UFUNCTION(BlueprintCallable)
    void DrawDebugMapOverlay();
    
    UFUNCTION(BlueprintCallable)
    bool CanConnectGridCells(FIntPoint Cell1, FIntPoint Cell2, int32 NeighbourIndex, bool bBlockGridObjects, bool bBlockHeight);
    
    UFUNCTION(BlueprintCallable)
    FIntVector ApproximateTerrainHeightAt(FIntVector position);
    
    UFUNCTION(BlueprintCallable)
    void AddSimulationActorToCell(FIntPoint position, ASimulationActor* SimulationActor);
    
    UFUNCTION(BlueprintCallable)
    void AddGridObjectToCells(AGridObject* GridObject, const TArray<FIntPoint>& Positions);
    
    UFUNCTION(BlueprintCallable)
    void AddGridObjectToCell(FIntPoint position, AGridObject* GridObject);
    
};

