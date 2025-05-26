#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AdvancedForceFeedback.h"
#include "LocAdvancedForceFeedbackSubsystem.generated.h"

class UForceFeedbackAttenuation;
class UForceFeedbackEffect;
class UObject;
class USceneComponent;
class USoundBase;

UCLASS(Blueprintable)
class LOC_API ULocAdvancedForceFeedbackSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    ULocAdvancedForceFeedbackSubsystem();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void StopAdvancedForceFeedback(UObject* WorldContext, FAdvancedForceFeedback AdvancedForceFeedback);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void SetPSControllerColor(UObject* WorldContext, FColor Color);
    
    UFUNCTION(BlueprintCallable)
    static UForceFeedbackEffect* ScaleForceFeedbackEffect(UForceFeedbackEffect* ForceFeedbackEffect, float Scale);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static FAdvancedForceFeedback PlayAdvancedForceFeedback(UObject* WorldContext, UForceFeedbackEffect* ForceFeedbackEffect, USoundBase* AudioBasedVibration, bool bForceFeedbackIsLooping, bool bPlayInWorld, FVector Location, USceneComponent* AttachToComponent, UForceFeedbackAttenuation* ForceFeedbackAttenuation, int32 FFConcurrency);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void ConfigureAudioFromControllerSubmix(UObject* WorldContext, USoundBase* AudioFromController, USoundBase*& OutAudio);
    
};

