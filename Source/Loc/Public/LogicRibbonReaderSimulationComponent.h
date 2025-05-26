#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SimulationActorComponent.h"
#include "CopyToolUseable.h"
#include "RibbonReaderEventDelegate.h"
#include "LogicRibbonReaderSimulationComponent.generated.h"

class ULogicConnectionSimulationComponent;
class ULogicInputSimulationComponent;
class ULogicOutputSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULogicRibbonReaderSimulationComponent : public USimulationActorComponent, public ICopyToolUseable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRibbonReaderEvent OnBitChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference InputReference;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 BitToWrite;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ULogicInputSimulationComponent> LogicInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ULogicOutputSimulationComponent> LogicOutput;
    
public:
    ULogicRibbonReaderSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateRibbonReaderOutput(ULogicConnectionSimulationComponent* Connection);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetBitToWriteTo(const int32 BitIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetBitToWriteTo() const;
    

    // Fix for true pure virtual functions not being implemented
};

