#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "EventSimulationComponent_String_EventDelegate.h"
#include "EventSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UEventSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventSimulationComponent_String_Event Event;
    
    UEventSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void CallEvent(const FString& EventId);
    
};

