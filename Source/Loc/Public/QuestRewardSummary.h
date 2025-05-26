#pragma once
#include "CoreMinimal.h"
#include "NavUserWidget.h"
#include "QuestRewardSummary.generated.h"

class UQuestConfig;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UQuestRewardSummary : public UNavUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UQuestConfig* QuestConfig;
    
public:
    UQuestRewardSummary();

    UFUNCTION(BlueprintCallable)
    void SetQuestConfig(UQuestConfig* InQuestConfig);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnQuestDataSet(UQuestConfig* NewQuestConfig);
    
};

