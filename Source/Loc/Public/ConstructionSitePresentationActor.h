#pragma once
#include "CoreMinimal.h"
#include "PresentationActor.h"
#include "EConstructionSiteState.h"
#include "ConstructionSitePresentationActor.generated.h"

class UConstructionSiteObjectSimulationComponent;
class USceneComponent;

UCLASS(Blueprintable)
class LOC_API AConstructionSitePresentationActor : public APresentationActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComponent_ReservedParent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComponent_UnderConstructionParent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComponent_FinishedParent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UConstructionSiteObjectSimulationComponent* ConstructionSiteSimulationComponent;
    
public:
    AConstructionSitePresentationActor(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnConstructionStarted(UConstructionSiteObjectSimulationComponent* InConstructionSiteSimulationComponent);
    
    UFUNCTION(BlueprintCallable)
    void OnConstructionSiteStateChanged(UConstructionSiteObjectSimulationComponent* InConstructionSiteSimulationComponent, EConstructionSiteState ConstructionSiteState);
    
    UFUNCTION(BlueprintCallable)
    void OnConstructionFinished(UConstructionSiteObjectSimulationComponent* InConstructionSiteSimulationComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ConstructionStartedEffects_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ConstructionSiteStateChangedEffects_Event(EConstructionSiteState ConstructionSiteState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ConstructionFinishedEffects_Event();
    
};

