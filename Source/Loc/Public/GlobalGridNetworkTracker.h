#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "GlobalGridNetworkTracker_Actor_StateDelegate.h"
#include "GlobalGridNetworkTracker.generated.h"

class UGlobalGridNetworkTracker;
class UObject;
class UPathNetworkAgentSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGlobalGridNetworkTracker : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalGridNetworkTracker_Actor_State OnAgentAddedToPathNetwork;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalGridNetworkTracker_Actor_State OnAgentRemovedFromPathNetwork;
    
    UGlobalGridNetworkTracker(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnAgentRemovedFromPathNetworkEvent(UPathNetworkAgentSimulationComponent* Agent);
    
    UFUNCTION(BlueprintCallable)
    void OnAgentAddedToPathNetworkEvent(UPathNetworkAgentSimulationComponent* Agent);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static UGlobalGridNetworkTracker* GetGlobalAITracker(const UObject* WorldContext);
    
};

