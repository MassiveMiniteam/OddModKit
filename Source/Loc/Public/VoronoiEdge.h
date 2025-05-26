#pragma once
#include "CoreMinimal.h"
#include "Fixed64.h"
#include "WorldMapPoint.h"
#include "VoronoiEdge.generated.h"

USTRUCT(BlueprintType)
struct FVoronoiEdge {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsBorderEdge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FWorldMapPoint A;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FWorldMapPoint B;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FWorldMapPoint N;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed64 EdgePart;
    
    LOC_API FVoronoiEdge();
};

