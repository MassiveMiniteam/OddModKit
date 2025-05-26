#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "BlackboardKeyType_IntVector.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LOC_API UBlackboardKeyType_IntVector : public UBlackboardKeyType {
    GENERATED_BODY()
public:
    UBlackboardKeyType_IntVector();

};

