#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "MultiUnlockCommand.generated.h"

class UUnlockableDataAsset;

UCLASS(Blueprintable)
class LOC_API UMultiUnlockCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UUnlockableDataAsset*> Unlockables;
    
    UMultiUnlockCommand();

};

