#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "EnemyWaveAgentSimulationComponent.generated.h"

class UEnemyWaveSpawnerSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UEnemyWaveAgentSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UEnemyWaveSpawnerSimulationComponent> MySpawner;
    
public:
    UEnemyWaveAgentSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetSpawner(UEnemyWaveSpawnerSimulationComponent* Spawner);
    
};

