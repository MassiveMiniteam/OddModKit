#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "OnPlayerIdentificationChanged_DelegateDelegate.h"
#include "PlayerIdentificationPresentationComponent.generated.h"

class UPlayerIdentificationSimulationComponent;
class UPlayerIdentificationSimulationReferenceComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPlayerIdentificationPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPlayerIdentificationChanged_Delegate OnPlayerIdentificationChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPlayerIdentificationSimulationComponent> PlayerIdentificationSimulationComponent;
    
public:
    UPlayerIdentificationPresentationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetIdentificationSimulation(UPlayerIdentificationSimulationComponent* PlayerIdentification);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnPlayerIdentificationSimulationChanged(UPlayerIdentificationSimulationComponent* IdentificationSimulationComponent);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerIdentificationReferenceChanged(UPlayerIdentificationSimulationReferenceComponent* Reference, UPlayerIdentificationSimulationComponent* IdentificationSimulation);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPlayerIdentificationChangedEvent(UPlayerIdentificationSimulationComponent* PlayerIdentification);
    
};

