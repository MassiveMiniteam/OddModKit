#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "LocAINode.h"
#include "BTTaskLoc_LocRunTree.generated.h"

class UBehaviorTree;

UCLASS(Blueprintable)
class LOC_API UBTTaskLoc_LocRunTree : public UBTTaskNode, public ILocAINode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBehaviorTree* TargetTree;
    
    UBTTaskLoc_LocRunTree();


    // Fix for true pure virtual functions not being implemented
};

