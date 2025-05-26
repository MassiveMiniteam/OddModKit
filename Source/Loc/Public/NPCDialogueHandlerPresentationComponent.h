#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PresentationActorComponent.h"
#include "Templates/SubclassOf.h"
#include "NPCDialogueHandlerPresentationComponent.generated.h"

class UDialogueConfig;
class UDialoguePlayerComponent;
class UDialogueQuestPromptWidget;
class UNPCQuestSelectorWidget;
class UQuestConfig;
class UQuestGiverSimulationComponent;
class UQuestManagerSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UNPCDialogueHandlerPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UDialoguePlayerComponent> DialoguePlayerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UQuestGiverSimulationComponent> QuestGiverComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UQuestManagerSimulationComponent> QuestManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UDialogueConfig*> BanterDialogConfigs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UDialogueConfig*> ReminderDialogueConfigs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDialogueQuestPromptWidget* CachedDialogueQuestPromptWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNPCQuestSelectorWidget* CachedQuestSelectorWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowOpenUIForActiveQuests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UNPCQuestSelectorWidget> QuestSelectorWidgetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDialogueQuestPromptWidget> QuestDialogWidgetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UQuestConfig* CachedQuestConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UQuestConfig* CompletedQuestConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag ConversationAnimationTag;
    
public:
    UNPCDialogueHandlerPresentationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void StartDialogue();
    
    UFUNCTION(BlueprintCallable)
    void OnSecondaryDialogueOver(UDialoguePlayerComponent* InDialoguePlayerComponent, UDialogueConfig* Dialogue);
    
    UFUNCTION(BlueprintCallable)
    void OnQuestSelectionCancelled(UNPCQuestSelectorWidget* Widget);
    
    UFUNCTION(BlueprintCallable)
    void OnQuestPromptWidgetClosed(UDialogueQuestPromptWidget* Widget, UQuestConfig* QuestConfig);
    
    UFUNCTION(BlueprintCallable)
    void OnQuestInteractionCancelled(UDialogueQuestPromptWidget* Widget, UQuestConfig* QuestConfig);
    
    UFUNCTION(BlueprintCallable)
    void OnQuestConfigSelected(UNPCQuestSelectorWidget* Widget, UQuestConfig* QuestConfig);
    
    UFUNCTION(BlueprintCallable)
    void OnQuestCompletedDialogueLineOver(UDialoguePlayerComponent* InDialoguePlayerComponent, UDialogueConfig* Dialogue);
    
    UFUNCTION(BlueprintCallable)
    void OnQuestCompleted(UDialogueQuestPromptWidget* Widget, UQuestConfig* QuestConfig);
    
    UFUNCTION(BlueprintCallable)
    void OnOfferedQuestAccepted(UDialogueQuestPromptWidget* Widget, UQuestConfig* QuestConfig);
    
    UFUNCTION(BlueprintCallable)
    void OnInitialDialogueOver(UDialoguePlayerComponent* InDialoguePlayerComponent, UDialogueConfig* Dialogue);
    
    UFUNCTION(BlueprintCallable)
    void OnDialogueCancelled(UDialoguePlayerComponent* InDialoguePlayerComponent, UDialogueConfig* Dialogue);
    
};

