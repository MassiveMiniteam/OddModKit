#pragma once
#include "CoreMinimal.h"
#include "Achievement_BasicCount.h"
#include "Achievement_MinionCount.generated.h"

class UItemMinionConfig;
class UObject;

UCLASS(Blueprintable)
class LOC_API UAchievement_MinionCount : public UAchievement_BasicCount {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UItemMinionConfig*> MinionConfigs;
    
public:
    UAchievement_MinionCount();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void AddCountForMinions(UObject* WorldContext, UItemMinionConfig* InMinion, int32 Amount);
    
};

