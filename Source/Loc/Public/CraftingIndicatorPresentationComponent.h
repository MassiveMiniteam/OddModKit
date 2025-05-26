#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "ECraftingStatusCode.h"
#include "CraftingIndicatorPresentationComponent.generated.h"

class URecipeConfig;
class URecipeProcessorSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UCraftingIndicatorPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<URecipeProcessorSimulationComponent> RecipeProcessorComponent;
    
public:
    UCraftingIndicatorPresentationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnCraftingStatusChanged(URecipeProcessorSimulationComponent* InRecipeProcessorComponent, URecipeConfig* Recipe, ECraftingStatusCode CraftingResponse);
    
};

