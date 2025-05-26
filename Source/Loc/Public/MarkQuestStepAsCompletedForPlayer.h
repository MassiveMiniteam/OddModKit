#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "MarkQuestStepAsCompletedForPlayer.generated.h"

class ASimulationPlayer;
class UQuestStepBehaviour;

UCLASS(Blueprintable)
class LOC_API UMarkQuestStepAsCompletedForPlayer : public USimulationCommand {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UQuestStepBehaviour* QuestStepBehaviour;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationPlayer* SimulationPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bSuccess;
    
public:
    UMarkQuestStepAsCompletedForPlayer();

};

