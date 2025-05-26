#pragma once
#include "CoreMinimal.h"
#include "Achievement_BasicCount.h"
#include "Achievement_ItemProductionCountByRecipe.generated.h"

class UItemConfig;
class URecipeConfig;

UCLASS(Blueprintable)
class LOC_API UAchievement_ItemProductionCountByRecipe : public UAchievement_BasicCount {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<URecipeConfig*> RecipeConfigs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UItemConfig*> ItemConfigs;
    
public:
    UAchievement_ItemProductionCountByRecipe();

};

