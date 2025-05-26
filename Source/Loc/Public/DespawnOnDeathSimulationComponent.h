#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "DeathComponentDelegateDelegate.h"
#include "SimulationTimerComponent.h"
#include "DespawnOnDeathSimulationComponent.generated.h"

class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UDespawnOnDeathSimulationComponent : public USimulationTimerComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed DespawnTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StartTimerDirectlyOnSimulationBegin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatsComponent;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDeathComponentDelegate OnBeforeDespawn;
    
    UDespawnOnDeathSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StartDeathTimer();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnDeathTriggered(UStatsComponent* StatsComp);
    
};

