#pragma once
#include "CoreMinimal.h"
#include "Achievement_BasicCount.h"
#include "Templates/SubclassOf.h"
#include "Achievement_GameplayAbilityByLocalPlayerCount.generated.h"

class ASimulationActor;
class UGameplayAbility;
class UObject;

UCLASS(Blueprintable)
class LOC_API UAchievement_GameplayAbilityByLocalPlayerCount : public UAchievement_BasicCount {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayAbility> AbilityClassToTrack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<ASimulationActor>> AllowedActorOwners;
    
public:
    UAchievement_GameplayAbilityByLocalPlayerCount();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void TrackAbility(UObject* WorldContext, TSubclassOf<UGameplayAbility> InAbilityClass, ASimulationActor* MinionOwningActor);
    
private:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    bool CanBeTracked(UObject* WorldContext, ASimulationActor* MinionOwningActor);
    
};

