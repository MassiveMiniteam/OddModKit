#pragma once
#include "CoreMinimal.h"
#include "EDestructionReason.h"
#include "SimulationActorComponent.h"
#include "ActorQueueComponent_DelegateDelegate.h"
#include "ActorQueueSimulationComponent.generated.h"

class ASimulationActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UActorQueueSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActorQueueComponent_Delegate OnActorQueueChanged;
    
private:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<ASimulationActor>> Queue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SizeLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBindPositionAttachmentToQueuePosition;
    
public:
    UActorQueueSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void RemoveFromQueue(ASimulationActor* Actor);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnActorShutdown(ASimulationActor* Actor, EDestructionReason Reason);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInQueue(ASimulationActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasFirstSpotInQueue(ASimulationActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASimulationActor*> GetQueuedActors() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumQueuedActors() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetActorIndexInQueue(ASimulationActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanRemoveActorFromQueue(ASimulationActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanAddActorToQueue(ASimulationActor* Actor) const;
    
    UFUNCTION(BlueprintCallable)
    void AddToQueue(ASimulationActor* Actor);
    
};

