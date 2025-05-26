#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FormationStrategy.generated.h"

UCLASS(Abstract, Blueprintable)
class LOC_API UFormationStrategy : public UObject {
    GENERATED_BODY()
public:
    UFormationStrategy();

};

