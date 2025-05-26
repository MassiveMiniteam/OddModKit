#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "ChildPresentationActor.h"
#include "ETrainTrackConnectionState.h"
#include "TrainsConnectionChangeDelegateParams.h"
#include "TrainTrackConnectionMarker.generated.h"

class UTrainTracksPoleConnectionSimulationComponent;

UCLASS(Blueprintable)
class LOC_API ATrainTrackConnectionMarker : public AChildPresentationActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference SimulationConnectionReference;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTrainTracksPoleConnectionSimulationComponent* MyConnectionComponent;
    
public:
    ATrainTrackConnectionMarker(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnContextUpdated();
    
    UFUNCTION(BlueprintCallable)
    void OnContextConnectionStateUpdated(FTrainsConnectionChangeDelegateParams DelegateParams);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyConnectionStateChange(ETrainTrackConnectionState NewState);
    
};

