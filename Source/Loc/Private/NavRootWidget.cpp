#include "NavRootWidget.h"
#include "Templates/SubclassOf.h"

UNavRootWidget::UNavRootWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->InputPriority = 0;
    this->bConsumeAllInput = false;
    this->bEnableInputOnShow = true;
    this->bPreSelectElement = true;
    this->FocusPath = NULL;
}

void UNavRootWidget::Show_Implementation() {
}

void UNavRootWidget::OnShow_Implementation() {
}

void UNavRootWidget::OnHide_Implementation() {
}

bool UNavRootWidget::NotifyMouseDropEvent(const FPointerEvent& MouseEvent) {
    return false;
}

void UNavRootWidget::LockPlayerNavigation(bool bLock) {
}

void UNavRootWidget::Hide_Implementation() {
}

bool UNavRootWidget::HasInput() {
    return false;
}

UWidget* UNavRootWidget::GetFirstFocussedElement(TSubclassOf<UWidget> WidgetClass) {
    return NULL;
}

void UNavRootWidget::EnableInputMerge() {
}

void UNavRootWidget::DisableInput() {
}


