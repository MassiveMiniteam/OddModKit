#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "Templates/SubclassOf.h"
#include "ConnectToTrainInventorySimulationComponent.generated.h"

class UGameplayEffect;
class UTrainTracksAgentSimulationComponent;
class UTrainTracksPoleBaseSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UConnectToTrainInventorySimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTrainTracksPoleBaseSimulationComponent* PoleComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName InventoryConnectionTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UGameplayEffect> GameplayEffectReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayEffect> GameplayEffectOnAgentWhileConnected;
    
public:
    UConnectToTrainInventorySimulationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnTrainAgentStopsMovement(const UTrainTracksPoleBaseSimulationComponent* Pole, const UTrainTracksAgentSimulationComponent* Agent);
    
    UFUNCTION(BlueprintCallable)
    void OnTrainAgentStartsMovement(const UTrainTracksPoleBaseSimulationComponent* Pole, const UTrainTracksAgentSimulationComponent* Agent);
    
    UFUNCTION(BlueprintCallable)
    void OnGameplayEffectRemoved();
    
};

