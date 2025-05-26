#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTCompositeNode.h"
#include "BTLocCompositeNode.generated.h"

UCLASS(Abstract, Blueprintable)
class LOC_API UBTLocCompositeNode : public UBTCompositeNode {
    GENERATED_BODY()
public:
    UBTLocCompositeNode();

};

