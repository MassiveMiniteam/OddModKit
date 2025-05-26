#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "LocAINode.h"
#include "BTTaskLoc_LocRunTreeDynamic.generated.h"

UCLASS(Blueprintable)
class LOC_API UBTTaskLoc_LocRunTreeDynamic : public UBTTaskNode, public ILocAINode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector TreeKey;
    
    UBTTaskLoc_LocRunTreeDynamic();


    // Fix for true pure virtual functions not being implemented
};

