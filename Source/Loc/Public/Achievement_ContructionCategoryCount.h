#pragma once
#include "CoreMinimal.h"
#include "Achievement_BasicCount.h"
#include "EBuildCategory.h"
#include "Achievement_ContructionCategoryCount.generated.h"

UCLASS(Blueprintable)
class LOC_API UAchievement_ContructionCategoryCount : public UAchievement_BasicCount {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBuildCategory Category;
    
public:
    UAchievement_ContructionCategoryCount();

};

