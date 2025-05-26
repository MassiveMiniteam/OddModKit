#pragma once
#include "CoreMinimal.h"
#include "DifficultySettings.h"
#include "SimulationCommand.h"
#include "OverwriteDifficultySettingsCommand.generated.h"

UCLASS(Blueprintable)
class LOCCORE_API UOverwriteDifficultySettingsCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FDifficultySettings DifficultySettings;
    
    UOverwriteDifficultySettingsCommand();

};

