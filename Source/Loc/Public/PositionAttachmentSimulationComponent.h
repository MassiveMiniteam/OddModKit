#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EDestructionReason.h"
#include "SimulationActorComponent.h"
#include "PositionAttachmentChanged_DelegateDelegate.h"
#include "PositionAttachmentSimulationComponent.generated.h"

class ASimulationActor;
class UPositionSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPositionAttachmentSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPositionAttachmentChanged_Delegate OnAttachmentChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bClearAttachmentOnLoad;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDestroyOwnerWhenAttachedTargetIsDestroyed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> PositionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> PositionComponentAttachedTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 AttachmentSlotIndex;
    
public:
    UPositionAttachmentSimulationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnAttachedToPositionChanged(UPositionSimulationComponent* AttachedToPositionComponent, FIntVector LastPosition);
    
    UFUNCTION(BlueprintCallable)
    void OnAttachedActorShutdown(ASimulationActor* AttachedSimulationActor, EDestructionReason Reason);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAttachmentSlotIndex() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UPositionSimulationComponent* GetAttachedToPositionComponent() const;
    
    UFUNCTION(BlueprintCallable)
    void AttachTo(UPositionSimulationComponent* NewPositionComponent, int32 Index);
    
};

