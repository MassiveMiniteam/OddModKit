#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "DifficultySettings.generated.h"

class UDifficultySettingsPreset;

USTRUCT(BlueprintType)
struct FDifficultySettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UDifficultySettingsPreset* Preset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FFixed> OverwriteValues;
    
    LOCCORE_API FDifficultySettings();
};

