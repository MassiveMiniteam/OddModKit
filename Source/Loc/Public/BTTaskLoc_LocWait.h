#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "Fixed.h"
#include "LocAINode.h"
#include "BTTaskLoc_LocWait.generated.h"

UCLASS(Blueprintable)
class LOC_API UBTTaskLoc_LocWait : public UBTTaskNode, public ILocAINode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed Duration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector DurationKey;
    
    UBTTaskLoc_LocWait();


    // Fix for true pure virtual functions not being implemented
};

