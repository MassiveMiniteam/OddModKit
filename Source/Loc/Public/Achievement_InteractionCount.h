#pragma once
#include "CoreMinimal.h"
#include "Achievement_BasicCount.h"
#include "Achievement_InteractionCount.generated.h"

class UConstructableConfig;

UCLASS(Blueprintable)
class LOC_API UAchievement_InteractionCount : public UAchievement_BasicCount {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UConstructableConfig*> ConstructableConfigs;
    
    UAchievement_InteractionCount();

};

