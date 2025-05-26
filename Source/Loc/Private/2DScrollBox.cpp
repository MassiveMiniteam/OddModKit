#include "2DScrollBox.h"
#include "Layout/Clipping.h"

U2DScrollBox::U2DScrollBox() {
    this->bIsVariable = false;
    this->Clipping = EWidgetClipping::ClipToBounds;
    this->ScrollBarVisibility = ESlateVisibility::Visible;
    this->AlwaysShowScrollbar = false;
    this->AlwaysShowScrollbarTrack = false;
    this->bAllowOverscroll = false;
    this->NavigationDestination = EDescendantScroll2DDestination::IntoView;
    this->ScrollWhenFocusChanges = EScrollWhenFocusChanges::NoScroll;
    this->bAllowMouseDragScrolling = true;
    this->MouseDragButton = E2DScrollMouseDragButton::Left;
}

void U2DScrollBox::SetScrollWhenFocusChanges(EScrollWhenFocusChanges NewScrollWhenFocusChanges) {
}

void U2DScrollBox::SetScrollOffset(FVector2D NewScrollOffset) {
}

void U2DScrollBox::SetScrollbarVisibility(ESlateVisibility NewScrollBarVisibility) {
}

void U2DScrollBox::SetScrollbarThickness(const FVector2D& NewScrollbarThickness) {
}

void U2DScrollBox::SetScrollBarPadding(const FMargin& NewScrollbarPadding) {
}

void U2DScrollBox::SetNavigationDestination(const EDescendantScroll2DDestination NewNavigationDestination) {
}

void U2DScrollBox::SetAlwaysShowScrollbar(bool NewAlwaysShowScrollbar) {
}

void U2DScrollBox::ScrollWidgetIntoView(UWidget* WidgetToFind, EDescendantScroll2DDestination ScrollDestination, FVector2D Padding) {
}

void U2DScrollBox::ScrollToStart() {
}

void U2DScrollBox::ScrollToNormalizedPosition(FVector2D NormalizedPosition, bool bAnimateScroll) {
}

void U2DScrollBox::ScrollToEnd() {
}

FVector2D U2DScrollBox::GetViewOffsetFraction() const {
    return FVector2D{};
}

FVector2D U2DScrollBox::GetViewFraction() const {
    return FVector2D{};
}

FVector2D U2DScrollBox::GetScrollOffsetOfEnd() const {
    return FVector2D{};
}

FVector2D U2DScrollBox::GetScrollOffset() const {
    return FVector2D{};
}

FVector2D U2DScrollBox::GetCurrentScrollPositionNormalized() {
    return FVector2D{};
}

void U2DScrollBox::EndInertialScrolling() {
}


