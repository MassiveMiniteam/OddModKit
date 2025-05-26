#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "DisassembleActorSimulationCommand.generated.h"

class ASimulationPlayer;
class UConstructionAssemblySimulationComponent;

UCLASS(Blueprintable)
class LOC_API UDisassembleActorSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationPlayer* SimulationPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bDisassembleImmediate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UConstructionAssemblySimulationComponent* AssemblyComponent;
    
    UDisassembleActorSimulationCommand();

};

