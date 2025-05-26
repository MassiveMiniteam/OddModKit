#pragma once
#include "CoreMinimal.h"
#include "Achievement_BasicCount.h"
#include "EBuildCategory.h"
#include "Achievement_PaintConstructableCount.generated.h"

UCLASS(Blueprintable)
class UAchievement_PaintConstructableCount : public UAchievement_BasicCount {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EBuildCategory> Category;
    
public:
    UAchievement_PaintConstructableCount();

};

