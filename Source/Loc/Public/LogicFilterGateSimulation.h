#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "CopyToolUseable.h"
#include "LogicFilterGateSimulation.generated.h"

class ULogicInputSimulationComponent;
class ULogicOutputSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULogicFilterGateSimulation : public USimulationActorComponent, public ICopyToolUseable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed FilterTime;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed FilterTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ULogicInputSimulationComponent> LogicInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ULogicOutputSimulationComponent> LogicOutput;
    
public:
    ULogicFilterGateSimulation(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetFilterTargetTime(FFixed TagetTime);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetFilterTargetTime();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetCurrentFilterTime();
    

    // Fix for true pure virtual functions not being implemented
};

