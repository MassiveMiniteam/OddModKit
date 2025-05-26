#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EDestructionReason.h"
#include "SimulationActorHook.generated.h"

class AActor;
class ASimulationActor;
class UPresentationActorComponent;
class USimulationActorComponent;
class UWorld;

UCLASS(Blueprintable)
class LOCCORE_API USimulationActorHook : public UObject {
    GENERATED_BODY()
public:
    USimulationActorHook();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSimulationActorPreDeserialize(UWorld* World, ASimulationActor* SimulationActor, bool bIsLoading);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSimulationActorEnd(UWorld* World, ASimulationActor* SimulationActor, EDestructionReason Reason);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSimulationActorComponentEnd(UWorld* World, USimulationActorComponent* Component, EDestructionReason Reason);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSimulationActorComponentBegin(UWorld* World, USimulationActorComponent* Component, bool bIsLoading);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSimulationActorBegin(UWorld* World, ASimulationActor* SimulationActor, bool bIsLoading);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPresentationActorEnd(UWorld* World, AActor* Actor, EDestructionReason Reason);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPresentationActorComponentEnd(UWorld* World, UPresentationActorComponent* Component, EDestructionReason Reason);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPresentationActorComponentBegin(UWorld* World, UPresentationActorComponent* Component, bool bIsLoading);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPresentationActorBegin(UWorld* World, AActor* Actor, bool bIsLoading);
    
};

