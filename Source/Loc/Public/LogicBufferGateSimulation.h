#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "CopyToolUseable.h"
#include "LogicBufferGateSimulation.generated.h"

class ULogicConnectionSimulationComponent;
class ULogicInputSimulationComponent;
class ULogicOutputSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULogicBufferGateSimulation : public USimulationActorComponent, public ICopyToolUseable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed BufferTime;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed BufferTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ULogicInputSimulationComponent> LogicInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ULogicOutputSimulationComponent> LogicOutput;
    
public:
    ULogicBufferGateSimulation(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetBufferTargetTime(FFixed NewBufferTime);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnInputSignalChanged(ULogicConnectionSimulationComponent* Input);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetCurrentBufferTime();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetBufferTargetTime();
    

    // Fix for true pure virtual functions not being implemented
};

