#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StaticMeshAndTransforms.generated.h"

class UStaticMesh;

USTRUCT(BlueprintType)
struct FStaticMeshAndTransforms {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> StaticMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTransform> Transforms;
    
    LOC_API FStaticMeshAndTransforms();
};

