#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FlockModifier.generated.h"

USTRUCT(BlueprintType)
struct FFlockModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Location;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ForceXY;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ForceZ;
    
    LOC_API FFlockModifier();
};

