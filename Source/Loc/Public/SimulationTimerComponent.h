#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "OnEventFiredDelegate.h"
#include "SimulationTimerDelegateDelegate.h"
#include "TimerFloatEventDelegate.h"
#include "SimulationTimerComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API USimulationTimerComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimulationTimerDelegate OnTimerStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimulationTimerDelegate OnTimerStopped;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnEventFired OnEventFired;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerFloatEvent OnTimerProgressChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimulationTimerDelegate OnCurrentDurationChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceTicking;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed ElapsedTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed TimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed CurrentDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsRunning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsCurrentlyLooping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsPaused;
    
public:
    USimulationTimerComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StopAndReset();
    
    UFUNCTION(BlueprintCallable)
    void SetupAndStart(FFixed Duration, bool bIsLooping);
    
    UFUNCTION(BlueprintCallable)
    void SetTimeDilation(FFixed NewDialation);
    
    UFUNCTION(BlueprintCallable)
    void ResetElapsedTime();
    
    UFUNCTION(BlueprintCallable)
    void Pause(bool NewIsPaused);
    
    UFUNCTION(BlueprintCallable)
    void OverwriteCurrentDuration(FFixed NewDuration);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEventFired_Event();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRunningAndNotPaused() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRunning() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPaused() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCurrentlyLooping() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetCurrentTimeDilation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetCurrentProgress() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetCurrentElapsedTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetCurrentDurationWithDilation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetCurrentDuration() const;
    
};

