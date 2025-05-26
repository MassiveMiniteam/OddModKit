#pragma once
#include "CoreMinimal.h"
#include "ItemStackingStrategy.h"
#include "ItemStackingStrategy_AlwaysSingleItem.generated.h"

UCLASS(Blueprintable)
class UItemStackingStrategy_AlwaysSingleItem : public UItemStackingStrategy {
    GENERATED_BODY()
public:
    UItemStackingStrategy_AlwaysSingleItem();

};

