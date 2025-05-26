#pragma once
#include "CoreMinimal.h"
#include "BiomeGeneratorPriorityEntry.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FBiomeGeneratorPriorityEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* Generator;
    
    LOC_API FBiomeGeneratorPriorityEntry();
};

