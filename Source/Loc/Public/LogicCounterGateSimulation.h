#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SimulationActorComponent.h"
#include "CopyToolUseable.h"
#include "CounterGateEventDelegate.h"
#include "LogicCounterGateSimulation.generated.h"

class ULogicConnectionSimulationComponent;
class ULogicInputSimulationComponent;
class ULogicOutputSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULogicCounterGateSimulation : public USimulationActorComponent, public ICopyToolUseable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCounterGateEvent OnCounterChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCounterGateEvent OnCounterTargetChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCounterGateEvent OnDisplayFlippedChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Counter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 TargetValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bLastInputValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bFlipDisplay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference LogicInputRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference LogicResetRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULogicInputSimulationComponent* LogicInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULogicInputSimulationComponent* LogicReset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULogicOutputSimulationComponent* LogicOutput;
    
public:
    ULogicCounterGateSimulation(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetTarget(int32 TargetIn);
    
    UFUNCTION(BlueprintCallable)
    void SetDisplayFlipped(bool FlipDisplay);
    
    UFUNCTION(BlueprintCallable)
    void SetCounter(int32 CounterIn);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnResetSignalChanged(ULogicConnectionSimulationComponent* Input);
    
    UFUNCTION(BlueprintCallable)
    void OnInputSignalChanged(ULogicConnectionSimulationComponent* Input);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDisplayFlipped() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTargetValue() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCounterValue() const;
    

    // Fix for true pure virtual functions not being implemented
};

