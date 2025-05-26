#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "BossTokenGeneratorIndexCommand.generated.h"

class UBossTokenGenerator;

UCLASS(Blueprintable)
class LOC_API UBossTokenGeneratorIndexCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UBossTokenGenerator* BossTokenGenerator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 TargetIndex;
    
    UBossTokenGeneratorIndexCommand();

};

