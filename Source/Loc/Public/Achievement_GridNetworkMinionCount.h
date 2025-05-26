#pragma once
#include "CoreMinimal.h"
#include "Achievement_BasicCount.h"
#include "Templates/SubclassOf.h"
#include "Achievement_GridNetworkMinionCount.generated.h"

class AGridNetwork;
class UItemConfig;

UCLASS(Blueprintable)
class UAchievement_GridNetworkMinionCount : public UAchievement_BasicCount {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AGridNetwork> GridNetworkType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UItemConfig*> Minions;
    
public:
    UAchievement_GridNetworkMinionCount();

};

