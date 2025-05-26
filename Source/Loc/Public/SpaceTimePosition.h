#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SpaceTimePosition.generated.h"

USTRUCT(BlueprintType)
struct FSpaceTimePosition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Location;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Time;
    
    LOC_API FSpaceTimePosition();
};

