#pragma once
#include "CoreMinimal.h"
#include "Achievement_BasicCount.h"
#include "Templates/SubclassOf.h"
#include "Achievement_GridNetworkCount.generated.h"

class AGridNetwork;

UCLASS(Blueprintable)
class LOC_API UAchievement_GridNetworkCount : public UAchievement_BasicCount {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AGridNetwork> GridNetworkType;
    
public:
    UAchievement_GridNetworkCount();

};

