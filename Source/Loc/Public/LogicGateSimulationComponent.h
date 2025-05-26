#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SimulationActorComponent.h"
#include "BooleanOperation.h"
#include "LogicGateSimulationComponent.generated.h"

class ULogicConnectionSimulationComponent;
class ULogicInputSimulationComponent;
class ULogicOutputSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULogicGateSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference OutputComponentReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULogicInputSimulationComponent*> Inputs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULogicOutputSimulationComponent* Output;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    BooleanOperation Mode;
    
public:
    ULogicGateSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void RefreshOutput(ULogicConnectionSimulationComponent* LogicConnection);
    
};

