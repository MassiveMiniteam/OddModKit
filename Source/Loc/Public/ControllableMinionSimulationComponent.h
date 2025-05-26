#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "SimulationActorComponent.h"
#include "ControllableMinionCallbackEventDelegate.h"
#include "ControllableMinionEventDelegate.h"
#include "ControllableMinionTagChangeEventDelegate.h"
#include "ControllableMinionSimulationComponent.generated.h"

class UMinionControllerSimulationBaseComponent;
class UPlayerIdentificationSimulationReferenceComponent;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UControllableMinionSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FControllableMinionEvent OnMinionFollowEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FControllableMinionTagChangeEvent OnMinionControlGroupTagChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FControllableMinionCallbackEvent OnMinionCalledBack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UMinionControllerSimulationBaseComponent* CurrentMinionController;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ControlGroupTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer BusyTags;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPlayerIdentificationSimulationReferenceComponent> PlayerIdentificationReference;
    
public:
    UControllableMinionSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetMinionController(UMinionControllerSimulationBaseComponent* NewMinionController);
    
    UFUNCTION(BlueprintCallable)
    void RemoveTag(FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBusy() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanBeCalled(UMinionControllerSimulationBaseComponent* NewMinionController);
    
    UFUNCTION(BlueprintCallable)
    void AddTag(FGameplayTag Tag);
    
};

