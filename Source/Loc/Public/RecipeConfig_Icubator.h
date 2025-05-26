#pragma once
#include "CoreMinimal.h"
#include "RecipeConfig.h"
#include "RecipeConfig_Icubator.generated.h"

class UStaticMesh;

UCLASS(Blueprintable)
class LOC_API URecipeConfig_Icubator : public URecipeConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TotalNeededInputAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UStaticMesh>> GrowStateMeshes_Plants;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UStaticMesh>> GrowStateMeshes_Soil;
    
    URecipeConfig_Icubator();

};

