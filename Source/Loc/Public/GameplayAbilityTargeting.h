#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameplayTagContainer.h"
#include "EGameplayAbilityFactionTargeting.h"
#include "EGameplayAbilitySelfTargeting.h"
#include "Templates/SubclassOf.h"
#include "GameplayAbilityTargeting.generated.h"

class ASimulationActor;
class UGameplayAbility;

UCLASS(Abstract, Blueprintable)
class LOC_API UGameplayAbilityTargeting : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameplayAbilitySelfTargeting SelfTargeting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameplayAbilityFactionTargeting FactionTargeting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer RequiredGameplayTagsOnTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ForbiddenGameplayTagsOnTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer RequiredTargetActorCellConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxUnitsHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDrawAreaOfEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSortTargetsByAITargetingPriorityStat;
    
public:
    UGameplayAbilityTargeting();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartDrawAreaOfEffect(const ASimulationActor* AbilityUser, TSubclassOf<UGameplayAbility> GameplayAbilityClass) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<ASimulationActor*> GetCurrentTargets(ASimulationActor* AbilityUser, TSubclassOf<UGameplayAbility> GameplayAbilityClass) const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<ASimulationActor*> GetAllTargetActorsByRelevantLocation(const ASimulationActor* AbilityUser, TSubclassOf<UGameplayAbility> GameplayAbilityClass) const;
    
};

