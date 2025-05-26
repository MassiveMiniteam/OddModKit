#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "DemandPresentationComponent.generated.h"

class UDemandSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UDemandPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDemandSimulationComponent* DemandSimulationComponent;
    
public:
    UDemandPresentationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnGameplayEffectStatusPolled(UDemandSimulationComponent* Component, bool bState);
    
};

