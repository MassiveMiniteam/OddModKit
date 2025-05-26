#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SimulationActorComponent.h"
#include "UnitGroupMemberSimulationComponent.generated.h"

class ASimulationActor;
class UBTStateMachineComponent;
class UGameplayAbility;
class UGettingAttackedSimulationComponent;
class UPositionSimulationComponent;
class USimulationBlackboardComponent;
class UStatsComponent;
class UUnitGroup;
class UUnitGroupMemberSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UUnitGroupMemberSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UUnitGroup* Group;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UBTStateMachineComponent> StateMachineComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USimulationBlackboardComponent> BlackboardComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> PositionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGettingAttackedSimulationComponent* GettingAttackedComponent;
    
public:
    UUnitGroupMemberSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetGroup(UUnitGroup* NewGroup);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnStatBoolAdded(UStatsComponent* StatsComp, FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable)
    void OnGettingAttacked(UGettingAttackedSimulationComponent* Component, ASimulationActor* Instigator, UGameplayAbility* Ability, bool bSuccess);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UUnitGroupMemberSimulationComponent*> GetOtherGroupMembers() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UUnitGroup* GetGroup() const;
    
    UFUNCTION(BlueprintCallable)
    UUnitGroup* CreateNewGroupAndAssignSelf();
    
};

