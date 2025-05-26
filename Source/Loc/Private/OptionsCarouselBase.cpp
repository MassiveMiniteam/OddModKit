#include "OptionsCarouselBase.h"

UOptionsCarouselBase::UOptionsCarouselBase() {
    this->bAllowCircularChange = true;
    this->CurrentOptionText = NULL;
}

void UOptionsCarouselBase::SwitchRight() {
}

void UOptionsCarouselBase::SwitchLeft() {
}

void UOptionsCarouselBase::SetCurrentOptionByIndex_NoNotify_Implementation(int32 Index) {
}

void UOptionsCarouselBase::SetCurrentOptionByIndex(int32 Index) {
}

void UOptionsCarouselBase::ResetOptions() {
}

void UOptionsCarouselBase::RenameOption(int32 Index, FText NewOptionName) {
}

int32 UOptionsCarouselBase::GetCurrentIndex() const {
    return 0;
}

void UOptionsCarouselBase::AddOptionFromIntPoint(FIntPoint Point) {
}

void UOptionsCarouselBase::AddOption(FText Option) {
}


