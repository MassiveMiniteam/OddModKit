#pragma once
#include "CoreMinimal.h"
#include "Sound/QuartzQuantizationUtilities.h"
#include "Sound/QuartzQuantizationUtilities.h"
#include "LocSimulationSubsystem.h"
#include "MusicSequenceSubsystem.generated.h"

class UMusicSequencePlayerSimulationComponent;
class UQuartzClockHandle;

UCLASS(Blueprintable)
class LOC_API UMusicSequenceSubsystem : public ULocSimulationSubsystem {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UQuartzClockHandle* ClockHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMusicSequencePlayerSimulationComponent*> ComponentsToPlaySequenceNextFrame;
    
public:
    UMusicSequenceSubsystem();

private:
    UFUNCTION(BlueprintCallable)
    void QuartzMetronomeCallback(FName ClockName, EQuartzCommandQuantization QuantizationType, int32 NumBars, int32 Beat, float BeatFraction);
    
    UFUNCTION(BlueprintCallable)
    void PlayQuantizedCallback(EQuartzCommandDelegateSubType EventType, FName Name);
    
};

