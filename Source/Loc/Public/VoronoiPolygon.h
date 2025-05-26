#pragma once
#include "CoreMinimal.h"
#include "SerializedSimulationObject.h"
#include "Fixed64.h"
#include "VoronoiEdge.h"
#include "WorldMapPoint.h"
#include "VoronoiPolygon.generated.h"

UCLASS(Blueprintable)
class UVoronoiPolygon : public USerializedSimulationObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FVoronoiEdge> Edges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FWorldMapPoint Center;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FWorldMapPoint AverageCenter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FWorldMapPoint MinEdgePosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FWorldMapPoint MaxEdgePosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed64 Radius;
    
    UVoronoiPolygon();

};

