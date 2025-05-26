#pragma once
#include "CoreMinimal.h"
#include "Achievement_BasicCount.h"
#include "Achievement_CountGenerateShopToken.generated.h"

class UItemConfig;

UCLASS(Blueprintable)
class UAchievement_CountGenerateShopToken : public UAchievement_BasicCount {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemConfig* ItemConfig;
    
public:
    UAchievement_CountGenerateShopToken();

};

