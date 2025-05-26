#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "ApplyGameplayEffectOnOverlapCorruptedSimulationComponent.generated.h"

class UElementStateSimulationComponent;
class UGameplayEffect;
class UPositionSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UApplyGameplayEffectOnOverlapCorruptedSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UGameplayEffect> GampeplayEffectClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UElementStateSimulationComponent> ElementStateSimulationComponent;
    
public:
    UApplyGameplayEffectOnOverlapCorruptedSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnGridPositionOverlap(UPositionSimulationComponent* ThisComponent, UPositionSimulationComponent* OtherComponent);
    
};

