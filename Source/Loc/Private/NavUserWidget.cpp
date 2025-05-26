#include "NavUserWidget.h"

UNavUserWidget::UNavUserWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->ShowVisibility = ESlateVisibility::Visible;
    this->HideVisibility = ESlateVisibility::Hidden;
    this->OnFocusGainedSound = NULL;
    this->OnFocusLostSound = NULL;
    this->OnShowSound = NULL;
    this->OnHideSound = NULL;
    this->bPushUIInputContextOnShow = true;
    this->bTryToNotHideUiBelow = false;
    this->bHideOnUICancel = false;
    this->bHideOnMouseClickOutOfScreen = false;
    this->bRemoveFromParentOnCancel = true;
    this->bCaptureMouseFocus = false;
    this->bIsNavigatable = true;
    this->ButtonPrompts = NULL;
    this->TutorialHintData = NULL;
    this->TutorialHintUIType = NULL;
    this->bIsShowing = false;
    this->bHasConstructed = false;
    this->InputUIContainer = NULL;
}

void UNavUserWidget::ShowTutorialHintIfPossible() {
}

void UNavUserWidget::Show(bool bMakeFocus, bool bMouse) {
}





void UNavUserWidget::MakeVisible(bool bMakeFocus, bool bMouse) {
}

void UNavUserWidget::MakeInvisible(bool bReAppendLastElement) {
}

bool UNavUserWidget::IsVisibleWithParent() {
    return false;
}

bool UNavUserWidget::IsPartOfFocusPath_Implementation() {
    return false;
}

void UNavUserWidget::Hide(bool bRemoveFromParent) {
}

bool UNavUserWidget::HasFocus() {
    return false;
}

UInputContainer* UNavUserWidget::GetUIInputContainer() const {
    return NULL;
}

UInputContainer* UNavUserWidget::GetInputContainer() {
    return NULL;
}

UWidget* UNavUserWidget::GetChildWidgetWithName(const FString& Name) {
    return NULL;
}

TArray<UWidget*> UNavUserWidget::GetAllChildWidgets() {
    return TArray<UWidget*>();
}

void UNavUserWidget::ClearFocus() {
}


