#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SimulationActorComponent.h"
#include "BTStateMachineStateEventDelegate.h"
#include "BTStateMachineStateGroupEventDelegate.h"
#include "BTStateMachineTagEventDelegate.h"
#include "Templates/SubclassOf.h"
#include "BTStateMachineComponent.generated.h"

class ASimulationActor;
class UBaseState;
class UBehaviorTreeTickerSimulationComponent;
class UGameplayAbility;
class UGettingAttackedSimulationComponent;
class USimulationBehaviorTreeComponent;
class USimulationBlackboardComponent;
class USimulationTimerComponent;
class UStateConditionStrategy;
class UStateGroup;
class UStateGroupMappingAsset;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UBTStateMachineComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBTStateMachineTagEvent OnTransitionToNewStateGroup;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBTStateMachineStateEvent OnTransitionToNewState;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBTStateMachineStateGroupEvent OnStateGroupChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStateGroupMappingAsset* StateGroupDefinitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UStateGroup* CurrentStateGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGameplayTag CurrentStateGroupTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UBaseState* CurrentState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UStateConditionStrategy>> CurrentCancelConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UBaseState> NextDesiredState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGameplayTag NextDesiredStateGroupTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bForceBothNextDesiredStateAndStateGroupUpdatesSimultaneously;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UBaseState>, UBaseState*> CachedStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UStateGroup>, UStateGroup*> CachedStateGroups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USimulationBehaviorTreeComponent> BehaviorTreeComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USimulationBlackboardComponent> BlackboardComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UBehaviorTreeTickerSimulationComponent> BehaviorTreeTickerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USimulationTimerComponent> StateUtilityTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> Stats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGettingAttackedSimulationComponent* GettingAttackedComponent;
    
public:
    UBTStateMachineComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void RequestTransitionToStateGroupWhenCurrentStateFinishes(FGameplayTag StateGroupTag);
    
    UFUNCTION(BlueprintCallable)
    void RequestTransitionToStateGroup(FGameplayTag StateGroupTag);
    
    UFUNCTION(BlueprintCallable)
    void RequestTransitionToState(TSubclassOf<UBaseState> NewState);
    
    UFUNCTION(BlueprintCallable)
    void RequestTransitionMostDesiredToState();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnUtilityTimerFired(USimulationTimerComponent* SimulationTimerComponent);
    
    UFUNCTION(BlueprintCallable)
    void OnStatBoolRemoved(UStatsComponent* StatsComponent, FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable)
    void OnGettingAttacked(UGettingAttackedSimulationComponent* Component, ASimulationActor* Instigator, UGameplayAbility* Ability, bool bSuccess);
    
    UFUNCTION(BlueprintCallable)
    void OnBehaviorTreeFinished(bool bIsLooping);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsValidStateGroupTag(FGameplayTag Tag) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UStateGroupMappingAsset* GetStateGroupDefinitions() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGameplayTag GetNextDesiredStateGroupTag() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UBaseState> GetNextDesiredState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGameplayTag GetCurrentStateGroupTag() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UStateGroup* GetCurrentStateGroup() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UBaseState* GetCurrentState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<TSubclassOf<UStateConditionStrategy>> GetCurrentCancelConditions() const;
    
};

