#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DifficultySettings.h"
#include "Fixed.h"
#include "LocSimulationSubsystem.h"
#include "OnDifficultyValueChangedDelegate.h"
#include "DifficultySettingsSubsystem.generated.h"

UCLASS(Blueprintable)
class LOCCORE_API UDifficultySettingsSubsystem : public ULocSimulationSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDifficultyValueChanged OnDifficultySettingsChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FDifficultySettings DifficultySettings;
    
public:
    UDifficultySettingsSubsystem();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetDifficultyValueAsBool(FGameplayTag Tag) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetDifficultyValue(FGameplayTag Tag) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FDifficultySettings GetDifficultySettings() const;
    
};

