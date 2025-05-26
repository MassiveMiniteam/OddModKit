#pragma once
#include "CoreMinimal.h"
#include "Achievement_BasicCount.h"
#include "Templates/SubclassOf.h"
#include "GameplayAbilityOnTargetsByLocalPlayerCount.generated.h"

class UGameplayAbility;
class UItemConfig;
class UObject;

UCLASS(Blueprintable)
class LOC_API UGameplayAbilityOnTargetsByLocalPlayerCount : public UAchievement_BasicCount {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayAbility> AbilityClassToTrack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UItemConfig*> ItemTargetsToTrack;
    
public:
    UGameplayAbilityOnTargetsByLocalPlayerCount();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void TrackAbilityAndItemTargets(UObject* WorldContext, TSubclassOf<UGameplayAbility> InAbilityClass, UItemConfig* ItemTarget);
    
};

