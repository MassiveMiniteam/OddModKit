#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AssemblyCondition.generated.h"

class UConstructionAssemblySimulationComponent;

UCLASS(Blueprintable)
class LOC_API UAssemblyCondition : public UObject {
    GENERATED_BODY()
public:
    UAssemblyCondition();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsFulfilled(UConstructionAssemblySimulationComponent* AssemblyComponent);
    
};

