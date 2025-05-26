#pragma once
#include "CoreMinimal.h"
#include "GridCellChangedEventDelegate.h"
#include "GridCell.generated.h"

class AGridObject;
class ASimulationActor;
class UBiomeCellInstance;
class UGridTileGroundLayer;
class UGridTileLandscapeLayer;

USTRUCT(BlueprintType)
struct FGridCell {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AGridObject*> Objects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASimulationActor*> SimulationActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGridCellChangedEvent OnGridCellChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGridCellChangedEvent OnGridObjectAdded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGridCellChangedEvent OnGridObjectRemoved;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int16 Height;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 SnowHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileGroundLayer* GroundLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileLandscapeLayer* LandscapeLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBiomeCellInstance* BiomeCell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bHasCustomGroundLayer: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bHasCustomLandscapeLayer: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bHasCustomHeight: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 ConnectedEdges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 ObjectEdgeConnectionModifier;
    
    LOC_API FGridCell();
};

