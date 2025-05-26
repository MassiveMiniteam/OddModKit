#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WorldCellMetaData.generated.h"

USTRUCT(BlueprintType)
struct FWorldCellMetaData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint GridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FName TargetName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsDestroyed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<uint8> Bytes;
    
    LOC_API FWorldCellMetaData();
};

