#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EDLSSMode.h"
#include "LocUpscalingSubsystem.generated.h"

UCLASS(Blueprintable)
class LOC_API ULocUpscalingSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    ULocUpscalingSubsystem();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsDLSSSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsDLSSModeSupported(EDLSSMode DLSSMode);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsDLSSEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<EDLSSMode> GetSupportedDLSSModes();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetDLSSScreenPercentageRange(float& MinScreenPercentage, float& MaxScreenPercentage);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetDLSSModeInformation(EDLSSMode DLSSMode, FVector2D ScreenResolution, bool& bIsSupported, float& OptimalScreenPercentage, bool& bIsFixedScreenPercentage, float& MinScreenPercentage, float& MaxScreenPercentage, float& OptimalSharpness);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText GetDLSSModeDisplayName(EDLSSMode DLSSMode);
    
    UFUNCTION(BlueprintCallable)
    void EnableDLSS(bool bIsEnabled);
    
    UFUNCTION(BlueprintCallable)
    void ApplyUpscalingSettings();
    
};

