#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ETestExitCode.h"
#include "LocGauntletTest.generated.h"

class UWorld;

UCLASS(Blueprintable)
class LOC_API ULocGauntletTest : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UWorld> TemporaryWorld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TestMaxDurationBeforeTimeout;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bActivateCheckSuccessTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SuccessCheckTimerInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SuccessCheckTimerInitialDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bActivateBenchmark;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBenchmarkFPSChart;
    
public:
    ULocGauntletTest();

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool TimerCheckForSuccess(ETestExitCode& OutCheckResult);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Tick(float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    void StopTestWithRuntimeErrorAndLog(const FString& NewLog);
    
    UFUNCTION(BlueprintCallable)
    void StopTest(ETestExitCode ExitCode);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSuccessCheckTimerFired();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartTest();
    
    UFUNCTION(BlueprintCallable)
    void LogError(const FString& NewLog);
    
    UFUNCTION(BlueprintCallable)
    void log(const FString& NewLog);
    
    UFUNCTION(BlueprintCallable)
    FString CreateAndGetBenchmarkFolder();
    
};

