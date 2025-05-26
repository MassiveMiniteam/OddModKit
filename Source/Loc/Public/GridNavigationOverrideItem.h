#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GridNavigationOverrideItem.generated.h"

USTRUCT(BlueprintType)
struct FGridNavigationOverrideItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint PositionOffset1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint PositionOffset2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GridNeigbourIndex;
    
    LOC_API FGridNavigationOverrideItem();
};

