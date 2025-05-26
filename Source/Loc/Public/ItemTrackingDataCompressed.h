#pragma once
#include "CoreMinimal.h"
#include "ItemTrackingData_SingleSnapshot.h"
#include "ItemTrackingDataCompressed.generated.h"

class UItemConfig;

USTRUCT(BlueprintType)
struct FItemTrackingDataCompressed {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UItemConfig* ItemConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FItemTrackingData_SingleSnapshot Buffer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<int32> Production;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<int32> Consumption;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 MaxSnapshots;
    
    LOC_API FItemTrackingDataCompressed();
};

