#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RecipeCondition.generated.h"

class URecipeProcessorSimulationComponent;

UCLASS(Abstract, Blueprintable)
class LOC_API URecipeCondition : public UObject {
    GENERATED_BODY()
public:
    URecipeCondition();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsConditionsFulfilled(const URecipeProcessorSimulationComponent* RecipeComponent) const;
    
};

