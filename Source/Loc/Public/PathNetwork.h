#pragma once
#include "CoreMinimal.h"
#include "GridNetwork.h"
#include "OnPathAgentEventDelegate.h"
#include "PathNetwork.generated.h"

class UObject;
class UPathNetworkAgentSimulationComponent;

UCLASS(Blueprintable)
class APathNetwork : public AGridNetwork {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPathAgentEvent OnAgentAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPathAgentEvent OnAgentRemoved;
    
private:
    UPROPERTY(EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UPathNetworkAgentSimulationComponent>> Agents;
    
public:
    APathNetwork(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool TryAddAgent(UPathNetworkAgentSimulationComponent* Agent);
    
    UFUNCTION(BlueprintCallable)
    void RemoveAgent(UPathNetworkAgentSimulationComponent* Agent, UObject* Origin);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<UPathNetworkAgentSimulationComponent*> GetAllAgents();
    
};

