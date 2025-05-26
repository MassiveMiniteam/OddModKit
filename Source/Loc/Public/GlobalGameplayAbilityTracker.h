#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "GlobalGameplayAbilityTracker_Ability_EventDelegate.h"
#include "Templates/SubclassOf.h"
#include "GlobalGameplayAbilityTracker.generated.h"

class ASimulationActor;
class UGameplayAbility;
class UGlobalGameplayAbilityTracker;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGlobalGameplayAbilityTracker : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalGameplayAbilityTracker_Ability_Event OnAbilityExecuted;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UGameplayAbility>, int32> GameplayAbilityTypeToCount;
    
public:
    UGlobalGameplayAbilityTracker(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnAbilityStarted(TSubclassOf<UGameplayAbility> Ability, ASimulationActor* Owner);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static UGlobalGameplayAbilityTracker* GetGlobalAbilityTracker(const UObject* WorldContext);
    
};

