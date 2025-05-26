#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "GameplayTagContainer.h"
#include "LocAINode.h"
#include "BTTaskLoc_LocWaitDynamic.generated.h"

UCLASS(Blueprintable)
class LOC_API UBTTaskLoc_LocWaitDynamic : public UBTTaskNode, public ILocAINode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag DurationStatsTag;
    
    UBTTaskLoc_LocWaitDynamic();


    // Fix for true pure virtual functions not being implemented
};

