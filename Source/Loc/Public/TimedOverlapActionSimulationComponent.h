#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "SimulationTimerComponent.h"
#include "Templates/SubclassOf.h"
#include "TimedOverlapEventDelegate.h"
#include "TimedOverlapActionSimulationComponent.generated.h"

class ASimulationActor;
class UPositionSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UTimedOverlapActionSimulationComponent : public USimulationTimerComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimedOverlapEvent OnStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimedOverlapEvent OnReset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed CoolDownTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStayActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bActivated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<ASimulationActor>> AcceptedOverlapActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPositionSimulationComponent* MyPositionComponent;
    
public:
    UTimedOverlapActionSimulationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnGridPositionOverlap(UPositionSimulationComponent* ThisComponent, UPositionSimulationComponent* OtherComponent);
    
};

