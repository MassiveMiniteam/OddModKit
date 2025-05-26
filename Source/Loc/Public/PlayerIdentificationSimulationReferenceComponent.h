#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "OnPlayerIdentificationReferenceChanged_DelegateDelegate.h"
#include "PlayerIdentificationSimulationReferenceComponent.generated.h"

class UPlayerIdentificationSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPlayerIdentificationSimulationReferenceComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPlayerIdentificationReferenceChanged_Delegate OnPlayerIdentificationChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPlayerIdentificationSimulationComponent> PlayerIdentificationSimulationComponent;
    
    UPlayerIdentificationSimulationReferenceComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetIdentificationSimulation(UPlayerIdentificationSimulationComponent* PlayerIdentification);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnPlayerIdentificationSimulationChanged(UPlayerIdentificationSimulationComponent* IdentificationSimulationComponent);
    
};

