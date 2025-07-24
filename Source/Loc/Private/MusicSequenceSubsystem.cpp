#include "MusicSequenceSubsystem.h"

UMusicSequenceSubsystem::UMusicSequenceSubsystem() {
    this->ClockHandle = NULL;
}

void UMusicSequenceSubsystem::QuartzMetronomeCallback(FName ClockName, EQuartzCommandQuantization QuantizationType, int32 NumBars, int32 Beat, float BeatFraction) {
}

void UMusicSequenceSubsystem::PlayQuantizedCallback(EQuartzCommandDelegateSubType EventType, FName Name) {
}


