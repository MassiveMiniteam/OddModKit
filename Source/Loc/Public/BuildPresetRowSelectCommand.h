#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "BuildPresetRowSelectCommand.generated.h"

class UBuildPresetsSimulationComponent;

UCLASS(Blueprintable)
class UBuildPresetRowSelectCommand : public USimulationCommand {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UBuildPresetsSimulationComponent* BuildPresetsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Row;
    
public:
    UBuildPresetRowSelectCommand();

};

