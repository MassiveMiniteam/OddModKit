#pragma once
#include "CoreMinimal.h"
#include "Fixed64.h"
#include "WorldMapPoint.generated.h"

USTRUCT(BlueprintType)
struct FWorldMapPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed64 X;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed64 Y;
    
    LOC_API FWorldMapPoint();
};

