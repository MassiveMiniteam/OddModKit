#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimulationActorComponent.h"
#include "PathAddOnEventDelegate.h"
#include "PathAddOnSimulationComponent.generated.h"

class AGridObject;
class ASimulationPlayer;
class UConstructionAssemblySimulationComponent;
class UGridNetworkAgentSimulationComponent;
class ULogicConnectionSimulationComponent;
class ULogicInputSimulationComponent;

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPathAddOnSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPathAddOnEvent OnAddOnActiveChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AGridObject> PathGridObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ULogicInputSimulationComponent> LogicInput;
    
public:
    UPathAddOnSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnRelocated(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingSimulationPlayer);
    
    UFUNCTION(BlueprintCallable)
    void OnPathBelowDisassemble(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingSimulationPlayer);
    
    UFUNCTION(BlueprintCallable)
    void OnLogicSignalChanged(ULogicConnectionSimulationComponent* Input);
    
    UFUNCTION(BlueprintCallable)
    void OnGridCellChanged(FIntPoint GridPosition);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAddOnActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AgentShouldWaitBeforeEntering(const UGridNetworkAgentSimulationComponent* Agent, FIntPoint HeadingIntoThisTile) const;
    
};

