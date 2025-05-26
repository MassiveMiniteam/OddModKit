#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "Templates/SubclassOf.h"
#include "ReplaceGridObjectCommand.generated.h"

class AGridObject;
class ASimulationActor;
class UConstructableConfig;

UCLASS(Blueprintable)
class LOC_API UReplaceGridObjectCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASimulationActor> NewSimulationActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Rotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UConstructableConfig* ConstructableConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    AGridObject* GridObject;
    
    UReplaceGridObjectCommand();

};

