#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AdditionalFullscreenDialogueWidget.generated.h"

class UDialoguePlayerComponent;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UAdditionalFullscreenDialogueWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDialoguePlayerComponent* DialoguePlayer;
    
public:
    UAdditionalFullscreenDialogueWidget();

    UFUNCTION(BlueprintCallable)
    void SetDialoguePlayer(UDialoguePlayerComponent* DialoguePlayerComponent);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDialogueSlideChanged_Event(UDialoguePlayerComponent* InDialoguePlayer, int32 Index);
    
    UFUNCTION(BlueprintCallable)
    void OnDialogueSlideChanged(UDialoguePlayerComponent* InDialoguePlayer, int32 Index);
    
};

