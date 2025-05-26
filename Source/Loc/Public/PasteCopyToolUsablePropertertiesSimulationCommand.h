#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "GridObjectCopyData.h"
#include "PasteCopyToolUsablePropertertiesSimulationCommand.generated.h"

class AGridObject;
class ASimulationPlayer;

UCLASS(Blueprintable)
class LOC_API UPasteCopyToolUsablePropertertiesSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGridObjectCopyData GridObjectCopyData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    AGridObject* TargetGridObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationPlayer* ExecutingSimulationPlayer;
    
    UPasteCopyToolUsablePropertertiesSimulationCommand();

};

