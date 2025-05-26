#include "NavRootCanvasWidget.h"

UNavRootCanvasWidget::UNavRootCanvasWidget() {
    this->CanvasPanel = NULL;
}

void UNavRootCanvasWidget::UnRegisterDragDropProcessor() {
}

void UNavRootCanvasWidget::RegisterDragDropProcessor() {
}

bool UNavRootCanvasWidget::OnMouseButtonUpEvent_Implementation(float MouseDistance, const FPointerEvent& MouseEvent) {
    return false;
}

bool UNavRootCanvasWidget::OnMouseButtonDownEvent_Implementation(const FPointerEvent& MouseEvent) {
    return false;
}


bool UNavRootCanvasWidget::GetHasVisibleChildren() {
    return false;
}

int32 UNavRootCanvasWidget::GetChildrenCount() const {
    return 0;
}

void UNavRootCanvasWidget::AddWidget(UUserWidget* UserWidget) {
}

void UNavRootCanvasWidget::AddChildToCanvas(UNavUserWidget* NavUserWidget) {
}


