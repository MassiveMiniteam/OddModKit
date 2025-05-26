#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Fixed.h"
#include "ReplaceSimulationComponent.h"
#include "AutoReplaceSelfOnUnlockComponent.generated.h"

class USimulationTimerComponent;
class UUnlockHandlingSimulationComponent;
class UUnlockableDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UAutoReplaceSelfOnUnlockComponent : public UReplaceSimulationComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUnlockHandlingSimulationComponent* UnlockHandler;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference TimerReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed DelayTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USimulationTimerComponent* Timer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUnlockableDataAsset* MyUnlockable;
    
public:
    UAutoReplaceSelfOnUnlockComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void TimerUpdated(USimulationTimerComponent* InTimer, FFixed Progess);
    
    UFUNCTION(BlueprintCallable)
    void TimerFired(USimulationTimerComponent* InTimer);
    
    UFUNCTION(BlueprintCallable)
    void OnUnlock(UUnlockableDataAsset* Unlockable);
    
};

