#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WorldCellMetaData_New.generated.h"

USTRUCT(BlueprintType)
struct FWorldCellMetaData_New {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint GridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TargetName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsDestroyed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> Bytes;
    
    LOC_API FWorldCellMetaData_New();
};

