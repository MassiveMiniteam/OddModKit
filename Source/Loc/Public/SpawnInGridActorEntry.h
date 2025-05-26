#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SpawnInGridActorEntry.generated.h"

class AGridObject;

USTRUCT(BlueprintType)
struct FSpawnInGridActorEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AGridObject> ActorClass;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntVector2 AmountRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRandomRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RotationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FIntVector> SpawnPositionsAndRotations;
    
    LOC_API FSpawnInGridActorEntry();
};

