#pragma once
#include "CoreMinimal.h"
#include "BiomeCellInstanceArray.generated.h"

class UBiomeCellInstance;

USTRUCT(BlueprintType)
struct FBiomeCellInstanceArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBiomeCellInstance*> BiomeCellInstances;
    
    LOC_API FBiomeCellInstanceArray();
};

