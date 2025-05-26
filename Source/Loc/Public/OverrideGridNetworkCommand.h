#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimulationCommand.h"
#include "Templates/SubclassOf.h"
#include "OverrideGridNetworkCommand.generated.h"

class ASimulationPlayer;
class UConstructableConfig;
class UGridNetworkManagerSubsystem;

UCLASS(Blueprintable)
class LOC_API UOverrideGridNetworkCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint Tile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGridNetworkManagerSubsystem> GridNetworkManagerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UConstructableConfig* ConstructableConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationPlayer* ExecutingSimulationPlayer;
    
    UOverrideGridNetworkCommand();

};

