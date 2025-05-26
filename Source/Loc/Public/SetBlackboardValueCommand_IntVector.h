#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimulationCommand.h"
#include "SetBlackboardValueCommand_IntVector.generated.h"

class USimulationBlackboardComponent;

UCLASS(Blueprintable)
class LOC_API USetBlackboardValueCommand_IntVector : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntVector IntVector;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FName KeyName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    USimulationBlackboardComponent* Blackboard;
    
    USetBlackboardValueCommand_IntVector();

};

