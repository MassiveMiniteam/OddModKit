#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ItemStackingConfig.generated.h"

class UItemStackingStrategy;
class UStaticMesh;

USTRUCT(BlueprintType)
struct FItemStackingConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemStackingStrategy> StackingStrategy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> Mesh_TwoItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> Mesh_ThreeOrMoreItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> Mesh_FullStack;
    
    LOC_API FItemStackingConfig();
};

