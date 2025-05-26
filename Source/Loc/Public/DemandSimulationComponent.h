#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "DemandSimulationBoolEventDelegate.h"
#include "Templates/SubclassOf.h"
#include "DemandSimulationComponent.generated.h"

class UGameplayEffect;
class UItemConfig;
class USimulationTimerComponent;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UDemandSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDemandSimulationBoolEvent OnGameplayEffectStatusPolled;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStatsComponent* StatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference DemandPollTimerReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed DemandSatisfiedPollTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USimulationTimerComponent* SimulationTimerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemConfig* DemandedItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UGameplayEffect>> GameplayEffectsToApply;
    
public:
    UDemandSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SatisfyDemand();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnTimerFired(USimulationTimerComponent* InSimulationTimerComponent);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemConfig* GetDemandedItem() const;
    
};

