#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "ActorChainComponent_DelegateDelegate.h"
#include "ActorChainSimulationComponent.generated.h"

class UActorChainSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UActorChainSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActorChainComponent_Delegate OnConnectionUpdated;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UActorChainSimulationComponent> Next;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UActorChainSimulationComponent> Previous;
    
public:
    UActorChainSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLast() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInFirstHalf() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFirst() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasPrevious() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasNext() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UActorChainSimulationComponent* GetPrevious() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UActorChainSimulationComponent* GetNext() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UActorChainSimulationComponent* GetLastActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UActorChainSimulationComponent* GetFirstActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<UActorChainSimulationComponent*> GetCompleteChainAsSortedArray() const;
    
    UFUNCTION(BlueprintCallable)
    void AttachInFrontOf(UActorChainSimulationComponent* Other);
    
    UFUNCTION(BlueprintCallable)
    void AttachBehind(UActorChainSimulationComponent* Other);
    
};

