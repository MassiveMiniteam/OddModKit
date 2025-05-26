#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SimulationActorComponent.h"
#include "AutomaticRecipeItemSupplyComponent.generated.h"

class UInventoryComponent;
class URecipeConfig;
class URecipeProcessorSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UAutomaticRecipeItemSupplyComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference InputInventoryReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference RecipeProcessorReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* InputInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URecipeProcessorSimulationComponent* RecipeProcessor;
    
public:
    UAutomaticRecipeItemSupplyComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnRecipeChanged(URecipeProcessorSimulationComponent* Component, URecipeConfig* Recipe);
    
    UFUNCTION(BlueprintCallable)
    void OnCraftingFinished(URecipeProcessorSimulationComponent* Component, URecipeConfig* Recipe);
    
};

