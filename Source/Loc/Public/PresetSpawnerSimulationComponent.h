#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "PresetSpawnerSimulationComponent.generated.h"

class ASimulationActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPresetSpawnerSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<ASimulationActor>> SpawnedActors;
    
    UPresetSpawnerSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void Spawn();
    
    UFUNCTION(BlueprintCallable)
    void Despawn();
    
};

