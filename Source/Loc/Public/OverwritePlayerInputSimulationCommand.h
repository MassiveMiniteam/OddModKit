#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SimulationCommand.h"
#include "OverwritePlayerInputSimulationCommand.generated.h"

class UPlayerInputForwardSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UOverwritePlayerInputSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UPlayerInputForwardSimulationComponent* PlayerInputForwardSimulationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer NewTags;
    
    UOverwritePlayerInputSimulationCommand();

};

