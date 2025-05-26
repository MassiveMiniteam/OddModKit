#pragma once
#include "CoreMinimal.h"
#include "EDestructionReason.h"
#include "SimulationActorComponent.h"
#include "RegisteredSimulationComponent.generated.h"

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API URegisteredSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    URegisteredSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void Unregister(EDestructionReason Reason);
    
    UFUNCTION(BlueprintCallable)
    void SetRegistration(bool bRegister);
    
    UFUNCTION(BlueprintCallable)
    void Register();
    
};

