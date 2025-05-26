#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "GameplayEffectEmitterHitSimulationCommand.generated.h"

class AGameplayEffectEmitter;
class ASimulationActor;

UCLASS(Blueprintable)
class LOC_API UGameplayEffectEmitterHitSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationActor* ActorHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    AGameplayEffectEmitter* GameplayEffectEmitter;
    
    UGameplayEffectEmitterHitSimulationCommand();

};

