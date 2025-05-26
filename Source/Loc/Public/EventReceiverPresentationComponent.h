#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "EventReceived_EventDelegate.h"
#include "EventReceiverPresentationComponent.generated.h"

class ASimulationActor;
class UEventSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UEventReceiverPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EventId;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventReceived_Event ReceivedEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASimulationActor* SimulationActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEventSimulationComponent* EventSimulationComponent;
    
public:
    UEventReceiverPresentationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnEventReceived(UEventSimulationComponent* InEventSimulationComponent, const FString& InEventID);
    
};

