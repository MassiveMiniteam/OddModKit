#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "SimulationHashRecord.h"
#include "RecordPlaybackHashSimulationCommand.generated.h"

class ASimulationManager;

UCLASS(Blueprintable)
class LOCCORE_API URecordPlaybackHashSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FSimulationHashRecord Record;
    
    URecordPlaybackHashSimulationCommand();

private:
    UFUNCTION(BlueprintCallable)
    void OnPostSimulationTick(ASimulationManager* SimulationManager);
    
};

