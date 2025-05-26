#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "ActivePlayersTracker.generated.h"

class ASimulationActor;
class ASimulationPlayer;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UActivePlayersTracker : public USimulationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<ASimulationPlayer*> ActivePlayers;
    
public:
    UActivePlayersTracker(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnPlayerLeft(ASimulationActor* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerJoined(ASimulationActor* Player);
    
};

