#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PresentationActorComponent.h"
#include "DialoguePlayer_EventDelegate.h"
#include "DialoguePlayer_Index_EventDelegate.h"
#include "DialoguePlayer_SlideConfig_EventDelegate.h"
#include "Templates/SubclassOf.h"
#include "DialoguePlayerComponent.generated.h"

class UDialogueBoxNavUserWidget;
class UDialogueConfig;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UDialoguePlayerComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialoguePlayer_Index_Event OnDialogueIndexChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialoguePlayer_SlideConfig_Event OnDialogueSlideChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialoguePlayer_Event OnDialogueStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialoguePlayer_Event OnDialogueStarted_Persistent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialoguePlayer_Event OnDialogueOver;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialoguePlayer_Event OnDialogueCancelled;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogueConfig* DialogueConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 DialogueIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDialogueBoxNavUserWidget> DialogUIClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag PlayerConversationAnimationTag;
    
public:
    UDialoguePlayerComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void Show(UDialogueConfig* InDialogueConfig);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnDialogueWidgetFinished(UDialogueBoxNavUserWidget* DialogueBox);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetDialogueIndex() const;
    
    UFUNCTION(BlueprintCallable)
    void CancelDialogue();
    
};

