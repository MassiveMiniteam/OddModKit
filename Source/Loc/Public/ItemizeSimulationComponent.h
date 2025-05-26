#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "ItemizeComponentEventDelegate.h"
#include "SimulationTimerComponent.h"
#include "ItemizeSimulationComponent.generated.h"

class UPositionSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UItemizeSimulationComponent : public USimulationTimerComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed DestroyAndItemizeTime;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemizeComponentEvent OnDespawnAndItemize;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> PositionComponent;
    
public:
    UItemizeSimulationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnTimerComponentFired(USimulationTimerComponent* SimulationTimerComponent);
    
public:
    UFUNCTION(BlueprintCallable)
    void InitiateTimedDestroyAndItemize();
    
    UFUNCTION(BlueprintCallable)
    void DestroyAndItemizeNow();
    
};

