#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "TimedGameplayStatCurceChanged_EventDelegate.h"
#include "CraftedRecipesCounterSimulationComponent.generated.h"

class URecipeConfig;
class URecipeProcessorSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UCraftedRecipesCounterSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimedGameplayStatCurceChanged_Event OnValueChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Counter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<URecipeProcessorSimulationComponent> RecipeProcessor;
    
public:
    UCraftedRecipesCounterSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnResourceCrafted(URecipeProcessorSimulationComponent* Component, URecipeConfig* Recipe);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCount() const;
    
};

