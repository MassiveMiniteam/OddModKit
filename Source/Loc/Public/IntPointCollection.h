#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IntPointCollection.generated.h"

USTRUCT(BlueprintType)
struct FIntPointCollection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> IntPoints;
    
    LOC_API FIntPointCollection();
};

