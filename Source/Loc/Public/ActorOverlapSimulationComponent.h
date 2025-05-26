#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "EffectOnOverlap.h"
#include "OnActorOverlapEventDelegate.h"
#include "SimulationTimerComponent.h"
#include "ActorOverlapSimulationComponent.generated.h"

class UPositionSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UActorOverlapSimulationComponent : public USimulationTimerComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActorOverlapEvent OnActorOverlapped;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed TickTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEffectOnOverlap> GameplayEffects;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TSet<TWeakObjectPtr<UPositionSimulationComponent>> OverlappingPositionComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> CachedPositionComponent;
    
public:
    UActorOverlapSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateOverlaps();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnOverlapTick(UPositionSimulationComponent* Other, FFixed Delta);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnOverlapStopped(UPositionSimulationComponent* Other);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnOverlapStarted(UPositionSimulationComponent* Other);
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapEvent_Native(UPositionSimulationComponent* ThisComponent, UPositionSimulationComponent* OtherComponent);
    
};

