#include "LocAdvancedForceFeedbackSubsystem.h"

ULocAdvancedForceFeedbackSubsystem::ULocAdvancedForceFeedbackSubsystem() {
}

void ULocAdvancedForceFeedbackSubsystem::StopAdvancedForceFeedback(UObject* WorldContext, FAdvancedForceFeedback AdvancedForceFeedback) {
}

void ULocAdvancedForceFeedbackSubsystem::SetPSControllerColor(UObject* WorldContext, FColor Color) {
}

UForceFeedbackEffect* ULocAdvancedForceFeedbackSubsystem::ScaleForceFeedbackEffect(UForceFeedbackEffect* ForceFeedbackEffect, float Scale) {
    return NULL;
}

FAdvancedForceFeedback ULocAdvancedForceFeedbackSubsystem::PlayAdvancedForceFeedback(UObject* WorldContext, UForceFeedbackEffect* ForceFeedbackEffect, USoundBase* AudioBasedVibration, bool bForceFeedbackIsLooping, bool bPlayInWorld, FVector Location, USceneComponent* AttachToComponent, UForceFeedbackAttenuation* ForceFeedbackAttenuation, int32 FFConcurrency) {
    return FAdvancedForceFeedback{};
}

void ULocAdvancedForceFeedbackSubsystem::ConfigureAudioFromControllerSubmix(UObject* WorldContext, USoundBase* AudioFromController, USoundBase*& OutAudio) {
}


