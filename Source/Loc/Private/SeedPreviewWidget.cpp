#include "SeedPreviewWidget.h"

USeedPreviewWidget::USeedPreviewWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->Size = 500;
    this->DynamicTexture = NULL;
}


UTexture2D* USeedPreviewWidget::GetTexture() const {
    return NULL;
}

void USeedPreviewWidget::GeneratePreview(const UObject* WorldContext, const FString& SeedText) {
}




