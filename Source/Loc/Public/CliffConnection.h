#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EGridDirectionVisualizationType.h"
#include "CliffConnection.generated.h"

USTRUCT(BlueprintType)
struct FCliffConnection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ConnectionHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> Connections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGridDirectionVisualizationType TypeCliff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RotationInDegreesCliff;
    
    LOC_API FCliffConnection();
};

