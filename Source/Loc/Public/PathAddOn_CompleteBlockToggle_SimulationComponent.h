#pragma once
#include "CoreMinimal.h"
#include "InteractionInterface.h"
#include "OnGateStateChangedDelegate.h"
#include "PathAddOnSimulationComponent.h"
#include "PathAddOn_CompleteBlockToggle_SimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPathAddOn_CompleteBlockToggle_SimulationComponent : public UPathAddOnSimulationComponent, public IInteractionInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGateStateChanged OnGateStateChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsClosed;
    
public:
    UPathAddOn_CompleteBlockToggle_SimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void Interact_Implementation();
    

    // Fix for true pure virtual functions not being implemented
};

