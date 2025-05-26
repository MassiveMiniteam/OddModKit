#include "UnlockableDataAsset.h"

UUnlockableDataAsset::UUnlockableDataAsset() {
    this->bIsUnlockedByDefault = false;
    this->Entitlement = NULL;
}

void UUnlockableDataAsset::Unlock(UObject* WorldContext) {
}

bool UUnlockableDataAsset::IsUnlocked(const UObject* WorldContext) {
    return false;
}

FText UUnlockableDataAsset::GetUnlockableTitle() const {
    return FText::GetEmpty();
}

TSoftObjectPtr<UTexture2D> UUnlockableDataAsset::GetUnlockableIcon() const {
    return NULL;
}

FText UUnlockableDataAsset::GetUnlockableDescription() const {
    return FText::GetEmpty();
}

FString UUnlockableDataAsset::GetRichTextId() const {
    return TEXT("");
}


