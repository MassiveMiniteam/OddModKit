#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuestCompleteWidget.generated.h"

class UQuestConfig;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UQuestCompleteWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UQuestCompleteWidget();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetQuest(UQuestConfig* QuestData);
    
};

