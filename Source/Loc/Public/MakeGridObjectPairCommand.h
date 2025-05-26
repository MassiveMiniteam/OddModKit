#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "MakeGridObjectPairCommand.generated.h"

class AGridObject;

UCLASS(Blueprintable)
class LOC_API UMakeGridObjectPairCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<AGridObject*> GridObjects;
    
    UMakeGridObjectPairCommand();

};

