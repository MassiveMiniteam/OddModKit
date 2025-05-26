#pragma once
#include "CoreMinimal.h"
#include "GridNetworkAgentSimulationComponent.h"
#include "PathAgentEventDelegate.h"
#include "PathNetworkAgentSimulationComponent.generated.h"

class UItemizeSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPathNetworkAgentSimulationComponent : public UGridNetworkAgentSimulationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPathAgentEvent OnAddedToPath;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPathAgentEvent OnRemovedFromPath;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UItemizeSimulationComponent> ItemizeComponent;
    
public:
    UPathNetworkAgentSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void InitiateDestroyAndItemize();
    
};

