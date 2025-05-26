#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "InputContextVisualizationPresentationComponent.generated.h"

class UInputContext;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UInputContextVisualizationPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContext* InputContext;
    
public:
    UInputContextVisualizationPresentationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void VisualizeInputContext(UInputContext* InInputContext);
    
    UFUNCTION(BlueprintCallable)
    void TickVisualization(UInputContext* InInputContext, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    void StopVisualizazion(UInputContext* InInputContext);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTickVisualization(UInputContext* InInputContext, float DeltaTime);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInputContextVisualizationStop(UInputContext* InInputContext);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInputContextVisualizationStart(UInputContext* InInputContext);
    
};

