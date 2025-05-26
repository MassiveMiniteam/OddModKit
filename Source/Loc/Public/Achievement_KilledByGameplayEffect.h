#pragma once
#include "CoreMinimal.h"
#include "Achievement_BasicCount.h"
#include "Achievement_KilledByGameplayEffect.generated.h"

class ASimulationActor;
class UGameplayEffect;

UCLASS(Blueprintable)
class LOC_API UAchievement_KilledByGameplayEffect : public UAchievement_BasicCount {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<ASimulationActor>> ObjectsToKill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<UGameplayEffect>> GameplayEffects;
    
public:
    UAchievement_KilledByGameplayEffect();

};

