#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GridNetworkCopyData.h"
#include "GridObjectCopyData.h"
#include "ConstructionsCopyData.generated.h"

USTRUCT(BlueprintType)
struct FConstructionsCopyData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGridObjectCopyData> GridObjectsCopyData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGridNetworkCopyData> GridNetworksCopyData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint DragExtent;
    
    LOC_API FConstructionsCopyData();
};

