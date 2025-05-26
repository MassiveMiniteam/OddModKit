#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GridNetworkEdge.generated.h"

USTRUCT(BlueprintType)
struct FGridNetworkEdge {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint A;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint B;
    
    LOC_API FGridNetworkEdge();
};

