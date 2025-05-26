#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ArrayOfGridPositions.generated.h"

USTRUCT(BlueprintType)
struct FArrayOfGridPositions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> GridPositions;
    
    LOC_API FArrayOfGridPositions();
};

