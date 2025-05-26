#pragma once
#include "CoreMinimal.h"
#include "PathAddOnSimulationComponent.h"
#include "PathAddOn_WaitIfItemConditionMatches_SimulationComponent.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPathAddOn_WaitIfItemConditionMatches_SimulationComponent : public UPathAddOnSimulationComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInventoryComponent> Inventory;
    
public:
    UPathAddOn_WaitIfItemConditionMatches_SimulationComponent(const FObjectInitializer& ObjectInitializer);

};

