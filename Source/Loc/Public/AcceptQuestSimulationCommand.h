#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "AcceptQuestSimulationCommand.generated.h"

class UQuestConfig;
class UQuestGiverSimulationComponent;
class UQuestManagerSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UAcceptQuestSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UQuestManagerSimulationComponent* QuestManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UQuestGiverSimulationComponent* QuestGiver;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UQuestConfig* Quest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bShouldPinQuest;
    
    UAcceptQuestSimulationCommand();

};

