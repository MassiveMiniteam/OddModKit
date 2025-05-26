#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SimulationCommand.h"
#include "ChangeStateGroupCommand.generated.h"

class UBTStateMachineComponent;

UCLASS(Blueprintable)
class LOC_API UChangeStateGroupCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UBTStateMachineComponent* StateMachineComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGameplayTag StateGroup;
    
    UChangeStateGroupCommand();

};

