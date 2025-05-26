#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlueprintBase.h"
#include "LocAINode.h"
#include "BTTaskLoc_BlueprintBase.generated.h"

UCLASS(Blueprintable)
class LOC_API UBTTaskLoc_BlueprintBase : public UBTTask_BlueprintBase, public ILocAINode {
    GENERATED_BODY()
public:
    UBTTaskLoc_BlueprintBase();


    // Fix for true pure virtual functions not being implemented
};

