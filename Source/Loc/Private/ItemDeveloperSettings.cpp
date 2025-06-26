#include "ItemDeveloperSettings.h"

UItemDeveloperSettings::UItemDeveloperSettings() {
}

FGameplayTag UItemDeveloperSettings::GetTagForItemConfig(UItemConfig* ItemConfig) {
    return FGameplayTag{};
}

UItemConfig* UItemDeveloperSettings::GetItemConfigForTag(FGameplayTag Tag) {
    return NULL;
}


