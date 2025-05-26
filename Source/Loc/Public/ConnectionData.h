#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ConnectionData.generated.h"

USTRUCT(BlueprintType)
struct FConnectionData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint OriginTile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint Direction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SlotIndex;
    
    LOC_API FConnectionData();
};

