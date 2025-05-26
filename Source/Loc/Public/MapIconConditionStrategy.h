#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MapIconConditionStrategy.generated.h"

class UMapIconSimulationComponent;

UCLASS(Abstract, Blueprintable)
class LOC_API UMapIconConditionStrategy : public UObject {
    GENERATED_BODY()
public:
    UMapIconConditionStrategy();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsCreationPossible(const UMapIconSimulationComponent* MapIconComponent) const;
    
};

