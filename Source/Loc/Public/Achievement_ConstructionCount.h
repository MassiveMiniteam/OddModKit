#pragma once
#include "CoreMinimal.h"
#include "Achievement_BasicCount.h"
#include "Achievement_ConstructionCount.generated.h"

class UConstructableConfig;

UCLASS(Blueprintable)
class LOC_API UAchievement_ConstructionCount : public UAchievement_BasicCount {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UConstructableConfig*> ConstructableConfigs;
    
public:
    UAchievement_ConstructionCount();

};

