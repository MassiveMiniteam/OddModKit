#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "UpdateCannonCommand.generated.h"

class UCannonSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UUpdateCannonCommand : public USimulationCommand {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UCannonSimulationComponent* CanonComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 NewRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 NewDistance;
    
public:
    UUpdateCannonCommand();

};

