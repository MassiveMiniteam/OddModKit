#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "AbilityList.h"
#include "EProjectileLaunchType.h"
#include "ProjectileParameters.h"
#include "Templates/SubclassOf.h"
#include "AbilityAndStateChangeOnProjectileComponent.generated.h"

class UBTStateMachineComponent;
class UBaseState;
class UGameplayAbilityComponent;
class UGameplayEffect;
class UProjectileSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UAbilityAndStateChangeOnProjectileComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EProjectileLaunchType, FAbilityList> ImpactAbilities;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EProjectileLaunchType, TSubclassOf<UBaseState>> FlightStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UProjectileSimulationComponent> ProjectileComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UGameplayAbilityComponent> AbilityComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UBTStateMachineComponent> StateMachineComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UGameplayEffect>> OnLaunchEffects;
    
    UAbilityAndStateChangeOnProjectileComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnProjectileLaunch(UProjectileSimulationComponent* ProjectileSimulationComponent, const FProjectileParameters& Parameters);
    
    UFUNCTION(BlueprintCallable)
    void OnProjectileAtTarget(UProjectileSimulationComponent* ProjectileSimulationComponent, const FProjectileParameters& Parameters);
    
};

