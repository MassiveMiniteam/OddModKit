#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemTrackingData_SingleSnapshot.h"
#include "ItemTrackingData.generated.h"

class UItemConfig;

USTRUCT(BlueprintType)
struct FItemTrackingData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UItemConfig* ItemConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FItemTrackingData_SingleSnapshot CurrentSnapshot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FItemTrackingData_SingleSnapshot> LongTermHistory;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FInt32Interval LifetimeExtrema_TotalCount;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FInt32Interval LifetimeExtrema_CountDuringSnapshot;
    
    LOC_API FItemTrackingData();
};

