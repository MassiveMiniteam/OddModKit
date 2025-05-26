#pragma once
#include "CoreMinimal.h"
#include "Fixed64.h"
#include "ItemTrackingDataCompressed.h"
#include "SnapShotHistory.generated.h"

class UItemConfig;

USTRUCT(BlueprintType)
struct FSnapShotHistory {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<UItemConfig*, FItemTrackingDataCompressed> Data;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed64 CurrentSnapshotLifeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64 SnapshotDurationInSec;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxSnapshots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed64 LifeTime;
    
    LOC_API FSnapShotHistory();
};

