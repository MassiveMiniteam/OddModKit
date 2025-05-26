#pragma once
#include "CoreMinimal.h"
#include "IndiciesToMaterials.generated.h"

class UMaterialInstanceDynamic;

USTRUCT(BlueprintType)
struct FIndiciesToMaterials {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, UMaterialInstanceDynamic*> IndexToMaterial;
    
    LOC_API FIndiciesToMaterials();
};

