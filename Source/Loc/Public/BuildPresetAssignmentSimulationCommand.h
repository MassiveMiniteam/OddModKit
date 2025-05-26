#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "BuildPresetAssignmentSimulationCommand.generated.h"

class IBuildToolAssignable;
class UBuildToolAssignable;
class UBuildPresetsSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UBuildPresetAssignmentSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UBuildPresetsSimulationComponent* BuildPresetsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TScriptInterface<IBuildToolAssignable> BuildToolAssignable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Row;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Slot;
    
public:
    UBuildPresetAssignmentSimulationCommand();

};

