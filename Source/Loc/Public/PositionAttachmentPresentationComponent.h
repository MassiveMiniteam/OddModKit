#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "PositionAttachmentPresentationComponent.generated.h"

class AActor;
class UPositionAttachmentSimulationComponent;
class UPositionSimulationComponent;
class USceneComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPositionAttachmentPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAttachRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionAttachmentSimulationComponent> PositionAttachmentSimulationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneComponent> AttachedToPresentationScene;
    
public:
    UPositionAttachmentPresentationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnAttachmentChanged(UPositionAttachmentSimulationComponent* AttachmentComponent, UPositionSimulationComponent* AttachedToPositionComponent);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetAttachedToPresentationActor() const;
    
    UFUNCTION(BlueprintCallable)
    void AttachToActor_PresentationOnly(AActor* TargetActor, int32 Index);
    
};

