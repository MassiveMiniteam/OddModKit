#pragma once
#include "CoreMinimal.h"
#include "Achievement_BasicCount.h"
#include "Templates/SubclassOf.h"
#include "Achievement_GameplayAbilityOnEnemiesByLocalPlayerCount.generated.h"

class ASimulationActor;
class UGameplayAbility;
class UObject;

UCLASS(Blueprintable)
class LOC_API UAchievement_GameplayAbilityOnEnemiesByLocalPlayerCount : public UAchievement_BasicCount {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayAbility> AbilityClassToTrack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASimulationActor*> EnemyTargetsToTrack;
    
public:
    UAchievement_GameplayAbilityOnEnemiesByLocalPlayerCount();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void TrackAbilityAndEnemyTargets(UObject* WorldContext, TSubclassOf<UGameplayAbility> InAbilityClass, ASimulationActor* EnemyTarget);
    
};

