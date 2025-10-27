#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "BalloonConfig.generated.h"

USTRUCT(BlueprintType)
struct FBalloonConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed ColorShift;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 MeshIndex;
    
    LOC_API FBalloonConfig();
};

