#pragma once
#include "CoreMinimal.h"
#include "DialogueQuestPrompt_EventDelegate.h"
#include "NavUserWidget.h"
#include "DialogueQuestPromptWidget.generated.h"

class AQuestInstance;
class ASimulationPlayer;
class UQuestConfig;
class UQuestGiverSimulationComponent;
class UQuestManagerSimulationComponent;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UDialogueQuestPromptWidget : public UNavUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueQuestPrompt_Event OnConfirm;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueQuestPrompt_Event OnCompleted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueQuestPrompt_Event OnDecline;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueQuestPrompt_Event OnAbort;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueQuestPrompt_Event OnCancel;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueQuestPrompt_Event OnUIClosed;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQuestManagerSimulationComponent* QuestManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UQuestConfig* QuestConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UQuestGiverSimulationComponent> QuestGiver;
    
public:
    UDialogueQuestPromptWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void OnQuestCompleted(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* QuestInstance, ASimulationPlayer* SimulationPlayer);
    
    UFUNCTION(BlueprintCallable)
    void OnQuestAccepted(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* QuestInstance);
    
    UFUNCTION(BlueprintCallable)
    void Decline();
    
    UFUNCTION(BlueprintCallable)
    void Confirm(bool bShouldPinQuest);
    
    UFUNCTION(BlueprintCallable)
    void Complete();
    
    UFUNCTION(BlueprintCallable)
    void Cancel();
    
};

