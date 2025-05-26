#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "BuildPresetToggleAssignmentSimulationCommand.generated.h"

class IBuildToolAssignable;
class UBuildToolAssignable;
class UBuildPresetsSimulationComponent;

UCLASS(Blueprintable)
class UBuildPresetToggleAssignmentSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UBuildPresetsSimulationComponent* BuildPresetsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TScriptInterface<IBuildToolAssignable> BuildToolAssignable;
    
    UBuildPresetToggleAssignmentSimulationCommand();

};

