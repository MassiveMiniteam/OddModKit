#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimulationActorComponent.h"
#include "GridNetworkAgentSimulationComponent.generated.h"

class AGridNetwork;
class USubGridMovementSimulationComponent;

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGridNetworkAgentSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USubGridMovementSimulationComponent> SubGridMovementComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AGridNetwork> AssignedNetwork;
    
public:
    UGridNetworkAgentSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetAssignedNetwork(AGridNetwork* NewNetwork);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnGridNetworkUpdated(AGridNetwork* Network);
    
    UFUNCTION(BlueprintCallable)
    void OnGridNetworkDestroyed(AGridNetwork* Network);
    
    UFUNCTION(BlueprintCallable)
    void OnArrivedAtNewTile(USubGridMovementSimulationComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    void IsAboutEnteringNewTile(USubGridMovementSimulationComponent* Component);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasValidAssignedNetwork() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint GetCurrentGridPosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AGridNetwork* GetAssignedNetwork() const;
    
};

