#include "OptionsCarouselWithTag.h"

UOptionsCarouselWithTag::UOptionsCarouselWithTag() {
    this->CurrentOptionText = NULL;
}

void UOptionsCarouselWithTag::SwitchCarouselRight_Implementation() {
}

void UOptionsCarouselWithTag::SwitchCarouselLeft_Implementation() {
}

void UOptionsCarouselWithTag::SetCurrentOptionByTag(FGameplayTag Tag) {
}

void UOptionsCarouselWithTag::SetCurrentCarouselOptionByIndex_NoNotify(int32 Index) {
}

void UOptionsCarouselWithTag::SetCurrentCarouselOptionByIndex(int32 Index) {
}

void UOptionsCarouselWithTag::ResetOptions() {
}

void UOptionsCarouselWithTag::ResetCarouselOptions() {
}

void UOptionsCarouselWithTag::RemoveOptionWithTag(FGameplayTag Tag) {
}

void UOptionsCarouselWithTag::RemoveCarouselOption(FCarouselOption OptionToRemove) {
}

int32 UOptionsCarouselWithTag::GetCurrentOptionIndex() const {
    return 0;
}

int32 UOptionsCarouselWithTag::GetCurrentIndex() const {
    return 0;
}

void UOptionsCarouselWithTag::AddCarouselOptionFromIntPoint(FGameplayTag Tag, FIntPoint Point) {
}

void UOptionsCarouselWithTag::AddCarouselOptionFromInt(FGameplayTag Tag, int32 Number) {
}

void UOptionsCarouselWithTag::AddCarouselOption(const FCarouselOption& CarouselOption) {
}


