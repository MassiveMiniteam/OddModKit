#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "BuildPresetClearRowSimulationCommand.generated.h"

class UBuildPresetsSimulationComponent;

UCLASS(Blueprintable)
class UBuildPresetClearRowSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UBuildPresetsSimulationComponent* BuildPresetsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Row;
    
    UBuildPresetClearRowSimulationCommand();

};

