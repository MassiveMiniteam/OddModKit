#pragma once
#include "CoreMinimal.h"
#include "GridTilePool.generated.h"

class UStaticMeshComponent;

USTRUCT(BlueprintType)
struct FGridTilePool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshComponent*> StaticMeshes;
    
    LOC_API FGridTilePool();
};

