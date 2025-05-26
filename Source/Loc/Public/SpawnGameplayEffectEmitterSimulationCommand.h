#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Fixed.h"
#include "SimulationCommand.h"
#include "Templates/SubclassOf.h"
#include "SpawnGameplayEffectEmitterSimulationCommand.generated.h"

class AGameplayEffectEmitter;
class ASimulationActor;
class ASimulationManager;

UCLASS(Blueprintable)
class LOC_API USpawnGameplayEffectEmitterSimulationCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASimulationActor> SimulationActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntVector WorldPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Rotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed WindupDuration;
    
    USpawnGameplayEffectEmitterSimulationCommand();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSpawnedEmitter(ASimulationManager* SimulationManager, AGameplayEffectEmitter* Emitter);
    
};

