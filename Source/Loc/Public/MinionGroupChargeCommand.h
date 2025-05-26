#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimulationCommand.h"
#include "MinionGroupChargeCommand.generated.h"

class AActor;
class ASimulationActor;
class UMinionControllerSimulationBaseComponent;

UCLASS(Blueprintable)
class LOC_API UMinionGroupChargeCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UMinionControllerSimulationBaseComponent* MinionController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<ASimulationActor*> Minions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntVector TargetPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    AActor* TargetActor;
    
    UMinionGroupChargeCommand();

};

