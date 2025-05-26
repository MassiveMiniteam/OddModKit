#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InteractionRequirementStrategy.generated.h"

class UInteractionPresentationComponent;

UCLASS(Blueprintable)
class LOC_API UInteractionRequirementStrategy : public UObject {
    GENERATED_BODY()
public:
    UInteractionRequirementStrategy();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool InteractionRequirementMet(const UInteractionPresentationComponent* InteractionComponent) const;
    
};

