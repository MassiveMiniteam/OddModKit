#include "Grid.h"
#include "WorldMapDataComponent.h"

AGrid::AGrid(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Seed = 0;
    this->ChunkSize = 10;
    this->WorldGenerationConfig = NULL;
    this->ChunkManager = NULL;
    this->WorldGenerator = NULL;
    this->WorldMapDataComponent = CreateDefaultSubobject<UWorldMapDataComponent>(TEXT("World Map Data"));
}

FIntVector AGrid::SnapToGrid(FIntVector CenterPosition, FIntPoint SizeInTiles, int32 Rotation) const {
    return FIntVector{};
}

bool AGrid::SetupGeneration(int32 InSeed, bool bIsLoading, FWorldGenerationInfo& InOutWorldGenerationInfo) {
    return false;
}

void AGrid::Setup(int32 InSeed, bool bIsLoading, FWorldGenerationInfo& InOutWorldGenerationInfo, bool bRerollInvalidSeed) {
}

void AGrid::SetGridTileSnowHeight(FIntPoint GridPosition, uint8 SnowHeight) {
}

void AGrid::SetGridTileLandscapeLayer(FIntPoint GridPosition, UGridTileLandscapeLayer* Layer) {
}

void AGrid::SetGridTileGroundLayer(FIntPoint GridPosition, UGridTileGroundLayer* Layer) {
}

void AGrid::RemoveSimulationActorToCell(FIntPoint position, ASimulationActor* SimulationActor) {
}

void AGrid::RemoveGridObjectToCells(AGridObject* GridObject, const TArray<FIntPoint>& Positions) {
}

void AGrid::RemoveGridObjectToCell(FIntPoint position, AGridObject* GridObject) {
}

void AGrid::NotifyGridCellMeshNeedsUpdateAround(FIntPoint GridPosition, int32 Radius) {
}

bool AGrid::IsValidGridPosition(FIntPoint position) const {
    return false;
}

bool AGrid::IsValidGridIndex(int32 Index) const {
    return false;
}

bool AGrid::IsTileWalkable(FIntPoint GridPosition) {
    return false;
}

bool AGrid::IsSimulationSphereCastIntersectedByLandscapeHeight(const FIntVector& Target, const FIntVector& Origin, int32 AllowedHeight, int32 Radius) {
    return false;
}

bool AGrid::IsRampCornerOrCliff(const FIntPoint& GridPosition) {
    return false;
}

bool AGrid::IsRampCornerAtPosition(FIntPoint GridPosition) {
    return false;
}

bool AGrid::IsRampAtPosition(FIntPoint GridPosition, bool bAlsoConsiderConstructableRamps) {
    return false;
}

bool AGrid::IsPositionInsideCone(const FIntVector& ConeCenter, const FIntVector& ConeCenterDirection, const FFixed& ConeAngle, const FIntVector& TestLocation) {
    return false;
}

bool AGrid::IsCliffCorner(const FIntPoint& GridPosition) {
    return false;
}

bool AGrid::IsCliffAtPositionWithMaxHeight(const FIntPoint& GridPosition, int32 Height) {
    return false;
}

bool AGrid::IsCliffAtPositionWithCliffHeight(const FIntPoint& GridPosition, int32 CliffHeight) {
    return false;
}

bool AGrid::IsCliffAtPositionIncludingDiagonals(FIntPoint GridPosition) {
    return false;
}

bool AGrid::IsCliffAtPosition(FIntPoint GridPosition) {
    return false;
}

bool AGrid::IsActorWithTagBetweenLocations(const FGameplayTag& Tag, const FIntVector& Target, const FIntVector& Origin, int32 LineThickness, TArray<AGridObject*>& OutIntersectingGridObjects) {
    return false;
}

FIntVector AGrid::GetWorldPosition(FIntPoint GridPosition) {
    return FIntVector{};
}

int32 AGrid::GetWorldHeightAtWorldPosition(FIntVector WorldPosition) {
    return 0;
}

int32 AGrid::GetWorldHeightAtGridPosition(FIntPoint GridPosition) {
    return 0;
}

FIntPoint AGrid::GetWestVector() {
    return FIntPoint{};
}

TArray<FIntPoint> AGrid::GetTilesSimulationSphereTrace(const FIntVector& Target, const FIntVector& Origin, int32 Radius) {
    return TArray<FIntPoint>();
}

TArray<FIntPoint> AGrid::GetTilesInLine(const FIntVector& Target, const FIntVector& Origin, int32 LineThickness) {
    return TArray<FIntPoint>();
}

FIntVector AGrid::GetTerrainNormalAt(const FIntPoint& GridPosition, FIntPoint& OutNeighbourGridPosition) {
    return FIntVector{};
}

TArray<FIntPoint> AGrid::GetSphereTraceAlongPath(const TArray<FIntVector>& TrackedPath, int32 Radius) {
    return TArray<FIntPoint>();
}

FIntPoint AGrid::GetSouthWestVector() {
    return FIntPoint{};
}

FIntPoint AGrid::GetSouthVector() {
    return FIntPoint{};
}

FIntPoint AGrid::GetSouthEastVector() {
    return FIntPoint{};
}

TArray<ASimulationActor*> AGrid::GetSimulationActorsWithinWorldDistanceAndInArc(const FSimulationActorConditionEvent& Condition, const FIntVector& WorldPosition, int32 DistanceInWorldUnits, const FIntVector& LookAtPosition, FFixed ArcAngle) const {
    return TArray<ASimulationActor*>();
}

TArray<ASimulationActor*> AGrid::GetSimulationActorsWithinWorldDistance(const FIntVector& WorldPosition, int32 DistanceInWorldUnits) const {
    return TArray<ASimulationActor*>();
}

TArray<ASimulationActor*> AGrid::GetSimulationActorsWithinTileDistance(const FIntPoint& GridCoordinates, int32 DistanceInGridUnits) const {
    return TArray<ASimulationActor*>();
}

TArray<ASimulationActor*> AGrid::GetSimulationActorsAt(const FIntPoint& position) const {
    return TArray<ASimulationActor*>();
}

TArray<ASimulationActor*> AGrid::GetSimulationActorsAndGridObjectsWithinWorldDistanceAndInArc(const FIntVector& WorldPosition, int32 DistanceInWorldUnits, FFixed ConeCenterLineRotation, FFixed ArcAngle) const {
    return TArray<ASimulationActor*>();
}

TArray<ASimulationActor*> AGrid::GetSimulationActorsAndGridObjectsAt(const FIntPoint& position) const {
    return TArray<ASimulationActor*>();
}

bool AGrid::GetRampDirection(FIntPoint GridPosition, FIntPoint& DirectionOut, bool& bIsTopPart) {
    return false;
}

FIntPoint AGrid::GetPositionForIndex(int32 Index) const {
    return FIntPoint{};
}

TMap<UBiomeCellInstance*, int32> AGrid::GetOverlappingBiomeCellInstanceCounts(FIntPoint Origin) {
    return TMap<UBiomeCellInstance*, int32>();
}

FIntPoint AGrid::GetNorthWestVector() {
    return FIntPoint{};
}

FIntPoint AGrid::GetNorthVector() {
    return FIntPoint{};
}

FIntPoint AGrid::GetNorthEastVector() {
    return FIntPoint{};
}

TArray<FIntPoint> AGrid::GetNeighbours(FIntPoint Origin, bool bIncludeDiagonal) const {
    return TArray<FIntPoint>();
}

UBiomeCellInstance* AGrid::GetMostOverlappingBiomeCell(FIntPoint Origin) {
    return NULL;
}

bool AGrid::GetIsFlatSeed() const {
    return false;
}

bool AGrid::GetIsBuildableArea(const FIntPoint& GridPosition) {
    return false;
}

int32 AGrid::GetIndexForPosition(FIntPoint position) const {
    return 0;
}

int32 AGrid::GetHeightAtGridPosition(FIntPoint GridPosition) {
    return 0;
}

uint8 AGrid::GetGridTileSnowHeight(FIntPoint GridPosition) {
    return 0;
}

UGridTileLandscapeLayer* AGrid::GetGridTileLandscapeLayer(FIntPoint GridPosition) {
    return NULL;
}

UGridTileGroundLayer* AGrid::GetGridTileGroundLayer(FIntPoint GridPosition) {
    return NULL;
}

TArray<AGridObject*> AGrid::GetGridObjectsWithinWorldDistance(const FIntVector& WorldPosition, int32 DistanceInWorldUnits) const {
    return TArray<AGridObject*>();
}

TArray<AGridObject*> AGrid::GetGridObjectsWithinTileDistance(const FIntPoint& GridCoordinates, int32 DistanceInGridUnits) const {
    return TArray<AGridObject*>();
}

TArray<AGridObject*> AGrid::GetGridObjectsAt(const FIntPoint& position) const {
    return TArray<AGridObject*>();
}

TArray<ASimulationActor*> AGrid::GetGridObjectsAndSimulationActorsWithinWorldDistance(const FIntVector& WorldPosition, int32 DistanceInWorldUnits) const {
    return TArray<ASimulationActor*>();
}

int32 AGrid::GetGeneratedHeightAt(int32 X, int32 Y) {
    return 0;
}

FIntPoint AGrid::GetEastVector() {
    return FIntPoint{};
}

int32 AGrid::GetCountForBiomeCellInstanceAroundOrigin(FIntPoint Origin, UBiomeCellInstance* BiomeCellInstanceToCheck) {
    return 0;
}

int32 AGrid::GetCountForBiomeCellConfigAroundOrigin(FIntPoint Origin, UBiomeCellConfig* BiomeCellConfig) {
    return 0;
}

FIntVector AGrid::GetClosestWalkablePositionFromAnotherPosition(const FIntVector& TargetPosition, const FIntVector& RequesterPosition, int32 MaxRadiusInWorldUnits) {
    return FIntVector{};
}

FIntVector AGrid::GetClosestWalkablePosition(const FIntVector& position) {
    return FIntVector{};
}

FIntPoint AGrid::GetClosestFreeCellExcluding(FIntPoint InGridCoordinates, bool& bSuccess, TArray<FIntPoint> ExcludingTiles, int32 MaxSize) {
    return FIntPoint{};
}

FIntPoint AGrid::GetClosestFreeCell(FIntPoint InGridCoordinates, bool& bSuccess, int32 MaxSize) {
    return FIntPoint{};
}

int32 AGrid::GetCliffHeightAtGridPosition(FIntPoint GridPosition) {
    return 0;
}

void AGrid::GetChunkCornerPositions(FChunkPosition ChunkPosition, FVector& LeftTop, FVector& RightTop, FVector& LeftBottom, FVector& RightBottom) {
}

TArray<FIntPoint> AGrid::GetCellsForArea(FIntVector CenterPosition, FIntPoint Area, int32 RotationOffset) {
    return TArray<FIntPoint>();
}

UBiomeCellInstance* AGrid::GetBiomeCellAt(FIntPoint GridPosition) {
    return NULL;
}

TArray<FIntPoint> AGrid::GetAllGridCoordinatesInRing(int32 MinRadius, int32 MaxRadius, const FIntPoint& BaseCoordinates) {
    return TArray<FIntPoint>();
}

TArray<FIntPoint> AGrid::GetAllGridCoordinatesInRadiusWordLocation(const FIntVector& WorldLocation, FFixed64 Radius) {
    return TArray<FIntPoint>();
}

TArray<FIntPoint> AGrid::GetAllGridCoordinatesInRadius(int32 Radius, const FIntPoint& BaseCoordinates) {
    return TArray<FIntPoint>();
}

TArray<FIntPoint> AGrid::GetAllGridCoordinatesInCone(FFixed MinRadius, FFixed MaxRadius, FIntPoint BaseCoordinates, FIntPoint TargetCoordinates, FFixed Angle) {
    return TArray<FIntPoint>();
}

TArray<FChunkPosition> AGrid::GetAllChunkPositionsInRadius(int32 ChunkRadius, const FIntPoint& BaseCoordinates) {
    return TArray<FChunkPosition>();
}

TArray<FIntVectorPair> AGrid::GetAllCellBordersInRadius(int32 CellRadiusInChunks, const FIntPoint& BaseCoordinates) {
    return TArray<FIntVectorPair>();
}

bool AGrid::FindClosestCliff(FIntPoint QueryPosition, int32 QueryRange, FIntPoint& CliffPosition) {
    return false;
}

void AGrid::DrawDebugMapOverlay() {
}

bool AGrid::CanConnectGridCells(FIntPoint Cell1, FIntPoint Cell2, int32 NeighbourIndex, bool bBlockGridObjects, bool bBlockHeight) {
    return false;
}

FIntVector AGrid::ApproximateTerrainHeightAt(FIntVector position) {
    return FIntVector{};
}

void AGrid::AddSimulationActorToCell(FIntPoint position, ASimulationActor* SimulationActor) {
}

void AGrid::AddGridObjectToCells(AGridObject* GridObject, const TArray<FIntPoint>& Positions) {
}

void AGrid::AddGridObjectToCell(FIntPoint position, AGridObject* GridObject) {
}


