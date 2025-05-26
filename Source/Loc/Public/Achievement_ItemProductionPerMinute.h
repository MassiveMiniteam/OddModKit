#pragma once
#include "CoreMinimal.h"
#include "Achievement_BasicCount.h"
#include "Achievement_ItemProductionPerMinute.generated.h"

class UItemConfig;

UCLASS(Blueprintable)
class LOC_API UAchievement_ItemProductionPerMinute : public UAchievement_BasicCount {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemConfig* ItemConfig;
    
public:
    UAchievement_ItemProductionPerMinute();

};

