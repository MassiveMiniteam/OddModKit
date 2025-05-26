#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SpawnObjectEntry.generated.h"

class AGridObject;

USTRUCT(BlueprintType)
struct FSpawnObjectEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint Offset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Rotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AGridObject> GridObjectClass;
    
    LOC_API FSpawnObjectEntry();
};

