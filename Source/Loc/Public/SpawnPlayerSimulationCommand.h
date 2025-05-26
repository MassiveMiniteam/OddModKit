#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimulationCommand.h"
#include "Templates/SubclassOf.h"
#include "SpawnPlayerSimulationCommand.generated.h"

class ASimulationActor;

UCLASS(Blueprintable)
class LOC_API USpawnPlayerSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASimulationActor> SimulationActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntVector WorldPosition;
    
    USpawnPlayerSimulationCommand();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPlayerRegistered(ASimulationActor* SimulationActor);
    
};

