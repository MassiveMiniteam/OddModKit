#pragma once
#include "CoreMinimal.h"
#include "Achievement_BasicCount.h"
#include "EBuildCategory.h"
#include "Achievement_UniqueConstructionCategoryCount.generated.h"

class UConstructableConfig;

UCLASS(Blueprintable)
class UAchievement_UniqueConstructionCategoryCount : public UAchievement_BasicCount {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EBuildCategory> Category;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UConstructableConfig*> UniqueConstructableConfigs;
    
public:
    UAchievement_UniqueConstructionCategoryCount();

};

