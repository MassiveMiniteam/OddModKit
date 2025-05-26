#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "ActorSlotsSimulationComponent.generated.h"

class ASimulationActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UActorSlotsSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<ASimulationActor>> ActorSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBindPositionAttachmentToSlotIndex;
    
public:
    UActorSlotsSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void RemoveActor(ASimulationActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasActorSlot(ASimulationActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetFirstEmptySlot() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetActorSlotIndex(ASimulationActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanRemoveActor(ASimulationActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanAddActor(ASimulationActor* Actor, int32 SlotIndex) const;
    
    UFUNCTION(BlueprintCallable)
    void AddActor(ASimulationActor* Actor, int32 SlotIndex);
    
};

