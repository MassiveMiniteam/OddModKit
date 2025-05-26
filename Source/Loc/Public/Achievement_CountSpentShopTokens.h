#pragma once
#include "CoreMinimal.h"
#include "Achievement_BasicCount.h"
#include "Achievement_CountSpentShopTokens.generated.h"

class UItemConfig;

UCLASS(Blueprintable)
class UAchievement_CountSpentShopTokens : public UAchievement_BasicCount {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemConfig* ShopToken;
    
    UAchievement_CountSpentShopTokens();

};

