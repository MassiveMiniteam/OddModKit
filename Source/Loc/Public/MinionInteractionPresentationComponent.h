#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "MinionInteractionPresentationComponent.generated.h"

class UControllableMinionSimulationComponent;
class UMinionControllerSimulationBaseComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UMinionInteractionPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UControllableMinionSimulationComponent> ControllableMinionComponent;
    
public:
    UMinionInteractionPresentationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnMinionFollowEvent(UMinionControllerSimulationBaseComponent* MinionController);
    
};

