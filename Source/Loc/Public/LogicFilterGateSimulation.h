#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "CopyToolUseable.h"
#include "LogicTickingComponentInterface.h"
#include "LogicFilterGateSimulation.generated.h"

class ULogicConnectionSimulationComponent;
class ULogicInputSimulationComponent;
class ULogicOutputSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULogicFilterGateSimulation : public USimulationActorComponent, public ICopyToolUseable, public ILogicTickingComponentInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed FilterTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULogicInputSimulationComponent* LogicInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULogicOutputSimulationComponent* LogicOutput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed FilterTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 LastTick;
    
public:
    ULogicFilterGateSimulation(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetFilterTargetTime(FFixed TagetTime);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnInputSignalChanged(ULogicConnectionSimulationComponent* Input);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetFilterTargetTime();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetCurrentFilterTime();
    

    // Fix for true pure virtual functions not being implemented
};

