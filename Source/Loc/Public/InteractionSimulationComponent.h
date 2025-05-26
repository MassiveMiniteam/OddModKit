#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "InteractionSimulationComponentEventDelegate.h"
#include "PlayerInteractionData.h"
#include "InteractionSimulationComponent.generated.h"

class ASimulationPlayer;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UInteractionSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInteractionSimulationComponentEvent OnInteractingPlayerChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPlayerInteractionData> InteractingPlayers;
    
public:
    UInteractionSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void RemoveInteractionPlayer(ASimulationPlayer* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInUse() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCurrentlyOccupied() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASimulationPlayer*> GetCurrentInteractingPlayers() const;
    
    UFUNCTION(BlueprintCallable)
    void AddInteractionPlayer(FPlayerInteractionData Player);
    
};

