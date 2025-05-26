#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GridObjectPlacementResult.generated.h"

USTRUCT(BlueprintType)
struct FGridObjectPlacementResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> ValidTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> InvalidTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> ValidExternalTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> InvalidExternalTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> ErrorMessages;
    
    LOC_API FGridObjectPlacementResult();
};

