#pragma once
#include "CoreMinimal.h"
#include "CopyToolUseable.h"
#include "PathAddOnSimulationComponent.h"
#include "PathAddOn_PassIfCarriedItemMatches_SimulationComponent.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPathAddOn_PassIfCarriedItemMatches_SimulationComponent : public UPathAddOnSimulationComponent, public ICopyToolUseable {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInventoryComponent> Inventory;
    
public:
    UPathAddOn_PassIfCarriedItemMatches_SimulationComponent(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

