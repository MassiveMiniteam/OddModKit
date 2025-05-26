#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OverlayVisualizationComponentUpdateDelegate.h"
#include "OverlayVisualizationComponent.generated.h"

class UUnlockableAction;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UOverlayVisualizationComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOverlayVisualizationComponentUpdate OnOverlayVisiblityChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bVisualizationIsActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUnlockableAction* UnlockableAction;
    
public:
    UOverlayVisualizationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void ToggleVisualization();
    
    UFUNCTION(BlueprintCallable)
    void StopVisualization();
    
    UFUNCTION(BlueprintCallable)
    void StartVisualization();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStopVisualization();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartVisualization();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsVisualizationCurrentlyActive();
    
};

