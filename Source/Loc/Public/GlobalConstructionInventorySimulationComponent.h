#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "RegisteredSimulationComponent.h"
#include "GlobalConstructionInventorySimulationComponent.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGlobalConstructionInventorySimulationComponent : public URegisteredSimulationComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference InventoryReference;
    
public:
    UGlobalConstructionInventorySimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryComponent* GetLinkedInventory() const;
    
};

