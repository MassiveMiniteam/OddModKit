#include "DynamicTexture.h"

UDynamicTexture::UDynamicTexture() {
    this->Texture = NULL;
}

void UDynamicTexture::UpdateTexture() {
}

void UDynamicTexture::SetPixel(int32 X, int32 Y, FLinearColor Color) {
}

void UDynamicTexture::Initialize(int32 InWidth, int32 InHeight, FLinearColor InClearColor, TEnumAsByte<TextureFilter> FilterMethod, bool bSRGB) {
}

int32 UDynamicTexture::GetWidth() {
    return 0;
}

UTexture2D* UDynamicTexture::GetTextureResource() {
    return NULL;
}

FLinearColor UDynamicTexture::GetPixelColor(int32 X, int32 Y) const {
    return FLinearColor{};
}

int32 UDynamicTexture::GetHeight() {
    return 0;
}

void UDynamicTexture::FillRect(int32 X, int32 Y, int32 Width, int32 Height, FLinearColor Color) {
}

void UDynamicTexture::Fill(FLinearColor Color) {
}

void UDynamicTexture::DrawLine(int32 X1, int32 Y1, int32 X2, int32 Y2, FLinearColor Color) {
}

void UDynamicTexture::Clear() {
}


