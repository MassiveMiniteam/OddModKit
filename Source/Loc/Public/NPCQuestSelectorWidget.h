#pragma once
#include "CoreMinimal.h"
#include "NavUserWidget.h"
#include "QuestSelectorWidget_EventDelegate.h"
#include "QuestSelectorWidget_QuestConfig_EventDelegate.h"
#include "NPCQuestSelectorWidget.generated.h"

class UQuestGiverSimulationComponent;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UNPCQuestSelectorWidget : public UNavUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestSelectorWidget_QuestConfig_Event OnQuestConfigSelected;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestSelectorWidget_Event OnQuestSelectionCancelled;
    
    UNPCQuestSelectorWidget();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetQuestGiver(UQuestGiverSimulationComponent* QuestGiverComponent);
    
    UFUNCTION(BlueprintCallable)
    void Cancel();
    
};

