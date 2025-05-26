#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SimulationCommand.h"
#include "EPlayAnimationCommandOptions.h"
#include "PlayAnimationCommand.generated.h"

class ASimulationActor;

UCLASS(Blueprintable)
class LOC_API UPlayAnimationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationActor* SimulationActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGameplayTag Tag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EPlayAnimationCommandOptions Option;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bChooseRandomAnimation;
    
    UPlayAnimationCommand();

};

