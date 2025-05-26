#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "InteractWithObjectCommand.generated.h"

class UObject;

UCLASS(Blueprintable)
class LOC_API UInteractWithObjectCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UObject* Object;
    
    UInteractWithObjectCommand();

};

