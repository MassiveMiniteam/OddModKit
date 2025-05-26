#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ERefreshRate.h"
#include "LocHFRSubsystem.generated.h"

UCLASS(Blueprintable)
class LOC_API ULocHFRSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    ULocHFRSubsystem();

private:
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void SetRefreshRate(ERefreshRate RefreshRate) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsHighFrameRateSupported();
    
};

