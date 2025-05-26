#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "ConstructionAssemblyPresentationComponent.generated.h"

class AGridObject;
class ASimulationPlayer;
class UConstructionAssemblySimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UConstructionAssemblyPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UConstructionAssemblySimulationComponent> AssemblyComponent;
    
public:
    UConstructionAssemblyPresentationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnItemsDroppedAfterDisassembly(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingPlayer, TArray<AGridObject*> Items);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDisassembleEvent(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingPlayer);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnDisassembleAfterReplace(UConstructionAssemblySimulationComponent* Component);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnAssemblyStartedEvent(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingPlayer);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnAssemblyDoneEvent(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingPlayer);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnAssemblyAfterReplace(UConstructionAssemblySimulationComponent* Component);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnAssemblyAfterMoving(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingPlayer);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HandleDisassemblyPrediction();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HandleAssemblyPredition();
    
};

