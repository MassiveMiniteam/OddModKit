#pragma once
#include "CoreMinimal.h"
#include "DialogueBoxWidget_EventDelegate.h"
#include "DialogueSlideConfig.h"
#include "NavUserWidget.h"
#include "DialogueBoxNavUserWidget.generated.h"

class UDialogueConfig;
class UDialoguePlayerComponent;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UDialogueBoxNavUserWidget : public UNavUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueBoxWidget_Event OnDialogueBoxDone;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogueConfig* DialogueConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDialoguePlayerComponent* DialoguePlayerComponent;
    
public:
    UDialogueBoxNavUserWidget();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetAsSubtitleOnly_Event(bool bSubtitleOnly);
    
    UFUNCTION(BlueprintCallable)
    void PrevSlide();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnDialogueCancelled(UDialoguePlayerComponent* DialoguePlayer, UDialogueConfig* Dialogue);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnDialogSlideChanged(UDialoguePlayerComponent* DialoguePlayer, FDialogueSlideConfig DialogueSlide);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnDialogOver(UDialoguePlayerComponent* DialoguePlayer, UDialogueConfig* Dialogue);
    
    UFUNCTION(BlueprintCallable)
    void NextSlide();
    
};

