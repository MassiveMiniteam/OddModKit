#pragma once
#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "Blueprint/UserWidget.h"
#include "EUIEvent.h"
#include "NavElementInterface.h"
#include "Templates/SubclassOf.h"
#include "UIEventReceiverInterface.h"
#include "NavUserWidget.generated.h"

class UButtonPromptBarItemSet;
class UInputActionData;
class UInputContainer;
class UNavFocusPath;
class USoundCue;
class UTutorialHintData;
class UTutorialHintNavWidget;
class UWidget;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UNavUserWidget : public UUserWidget, public INavElementInterface, public IUIEventReceiverInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESlateVisibility ShowVisibility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESlateVisibility HideVisibility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* OnFocusGainedSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* OnFocusLostSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* OnShowSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* OnHideSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPushUIInputContextOnShow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTryToNotHideUiBelow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHideOnUICancel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHideOnMouseClickOutOfScreen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRemoveFromParentOnCancel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCaptureMouseFocus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsNavigatable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UButtonPromptBarItemSet* ButtonPrompts;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTutorialHintData* TutorialHintData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTutorialHintNavWidget> TutorialHintUIType;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsShowing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasConstructed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContainer* InputUIContainer;
    
public:
    UNavUserWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void ShowTutorialHintIfPossible();
    
public:
    UFUNCTION(BlueprintCallable)
    void Show(bool bMakeFocus, bool bMouse);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUIEvent(EUIEvent Event);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShow();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHide();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFirstConstruct();
    
    UFUNCTION(BlueprintCallable)
    void MakeVisible(bool bMakeFocus, bool bMouse);
    
    UFUNCTION(BlueprintCallable)
    void MakeInvisible(bool bReAppendLastElement);
    
    UFUNCTION(BlueprintCallable)
    bool IsVisibleWithParent();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsPartOfFocusPath();
    
    UFUNCTION(BlueprintCallable)
    void Hide(bool bRemoveFromParent);
    
    UFUNCTION(BlueprintCallable)
    bool HasFocus();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputContainer* GetUIInputContainer() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputContainer* GetInputContainer();
    
    UFUNCTION(BlueprintCallable)
    UWidget* GetChildWidgetWithName(const FString& Name);
    
    UFUNCTION(BlueprintCallable)
    TArray<UWidget*> GetAllChildWidgets();
    
    UFUNCTION(BlueprintCallable)
    void ClearFocus();
    

    // Fix for true pure virtual functions not being implemented
    UFUNCTION()
    void OnProcessInput(UNavFocusPath* Path, int32 PathIndex, UInputActionData* InputData) override PURE_VIRTUAL(OnProcessInput,);
    
};

