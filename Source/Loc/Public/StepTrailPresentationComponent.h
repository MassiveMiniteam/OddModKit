#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "StepTrailPresentationComponent.generated.h"

class UGridNetworkAgentPresentationComponent;
class UGridNetworkAgentSimulationComponent;
class UNiagaraComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UStepTrailPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UNiagaraComponent> ParticleSystemComponent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UGridNetworkAgentSimulationComponent> GridNetworkAgentSimulationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UGridNetworkAgentPresentationComponent> GridNetworkAgentPresentationComponent;
    
public:
    UStepTrailPresentationComponent(const FObjectInitializer& ObjectInitializer);

};

