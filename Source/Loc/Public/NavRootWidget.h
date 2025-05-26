#pragma once
#include "CoreMinimal.h"
#include "Input/Events.h"
#include "Blueprint/UserWidget.h"
#include "InputReceiver.h"
#include "Templates/SubclassOf.h"
#include "NavRootWidget.generated.h"

class UNavFocusPath;
class UWidget;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UNavRootWidget : public UUserWidget, public IInputReceiver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InputPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bConsumeAllInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableInputOnShow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPreSelectElement;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNavFocusPath* FocusPath;
    
public:
    UNavRootWidget();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Show();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnShow();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnHide();
    
    UFUNCTION(BlueprintCallable)
    bool NotifyMouseDropEvent(const FPointerEvent& MouseEvent);
    
    UFUNCTION(BlueprintCallable)
    void LockPlayerNavigation(bool bLock);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Hide();
    
    UFUNCTION(BlueprintCallable)
    bool HasInput();
    
protected:
    UFUNCTION(BlueprintCallable)
    UWidget* GetFirstFocussedElement(TSubclassOf<UWidget> WidgetClass);
    
public:
    UFUNCTION(BlueprintCallable)
    void EnableInputMerge();
    
    UFUNCTION(BlueprintCallable)
    void DisableInput();
    

    // Fix for true pure virtual functions not being implemented
};

