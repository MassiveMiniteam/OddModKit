#pragma once
#include "CoreMinimal.h"
#include "Achievement_BasicCount.h"
#include "Achievement_AddMaximumCount.generated.h"

class UObject;

UCLASS(Blueprintable)
class LOC_API UAchievement_AddMaximumCount : public UAchievement_BasicCount {
    GENERATED_BODY()
public:
    UAchievement_AddMaximumCount();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void AddmaximumCountCheck(UObject* WorldContext, int32 Amount);
    
};

