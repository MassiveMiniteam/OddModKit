#pragma once
#include "CoreMinimal.h"
#include "PathAddOnSimulationComponent.h"
#include "PressurePlateEventDelegate.h"
#include "PathAddOn_PressurePlate_SimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPathAddOn_PressurePlate_SimulationComponent : public UPathAddOnSimulationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPressurePlateEvent OnAgentEntered;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPressurePlateEvent OnAgentLeft;
    
    UPathAddOn_PressurePlate_SimulationComponent(const FObjectInitializer& ObjectInitializer);

};

