#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "UnlockCommand.generated.h"

class UUnlockableDataAsset;

UCLASS(Blueprintable)
class LOC_API UUnlockCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UUnlockableDataAsset* Unlockable;
    
    UUnlockCommand();

};

