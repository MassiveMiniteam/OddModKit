#pragma once
#include "CoreMinimal.h"
#include "QuestStepBehaviour.h"
#include "QuestStepBehaviour_ItemsInQuestInstanceInventory.generated.h"

class UItemConfig;

UCLASS(Blueprintable)
class LOC_API UQuestStepBehaviour_ItemsInQuestInstanceInventory : public UQuestStepBehaviour {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemConfig* NeededItem;
    
    UQuestStepBehaviour_ItemsInQuestInstanceInventory();

};

