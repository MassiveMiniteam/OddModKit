#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimulationCommand.h"
#include "Templates/SubclassOf.h"
#include "SpawnActorSimulationCommand.generated.h"

class ASimulationActor;

UCLASS(Blueprintable)
class LOC_API USpawnActorSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASimulationActor> SimulationActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntVector WorldPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Rotation;
    
    USpawnActorSimulationCommand();

};

