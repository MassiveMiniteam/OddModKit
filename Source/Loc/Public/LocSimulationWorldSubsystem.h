#pragma once
#include "CoreMinimal.h"
#include "LocSimulationSubsystem.h"
#include "LocSimulationWorldSubsystem.generated.h"

class UDifficultySettingsSubsystem;

UCLASS(Blueprintable)
class LOC_API ULocSimulationWorldSubsystem : public ULocSimulationSubsystem {
    GENERATED_BODY()
public:
    ULocSimulationWorldSubsystem();

protected:
    UFUNCTION(BlueprintCallable)
    void OnDifficultySettingsChanged(UDifficultySettingsSubsystem* Subsystem);
    
};

