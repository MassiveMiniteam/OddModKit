#include "MMTUnrealToolsBPLibrary.h"

UMMTUnrealToolsBPLibrary::UMMTUnrealToolsBPLibrary() {
}

void UMMTUnrealToolsBPLibrary::VisualLogPosition(UObject* Owner, FVector Position, float SphereRadius, FColor Color, const FString& Text) {
}

FVector2D UMMTUnrealToolsBPLibrary::SetWidgetScreenPositionFromWorldPosition(UUserWidget* Widget, FVector WorldLocation, FVector2D Alignment, bool ClampToScreen) {
    return FVector2D{};
}

void UMMTUnrealToolsBPLibrary::SavePackage(const UObject* CreatedAsset, UPackage* PackageNew) {
}

void UMMTUnrealToolsBPLibrary::ReSavePackage(const UObject* CreatedAsset) {
}

FVector2D UMMTUnrealToolsBPLibrary::ProjectWorldToScreenEvenIfBehindCamera(APlayerController* Player, const FVector& WorldPosition) {
    return FVector2D{};
}

FVector2D UMMTUnrealToolsBPLibrary::GetNormalizedViewportPositionInGeometry(UObject* WorldContextObject, FGeometry Geometry, FVector2D ViewportPosition) {
    return FVector2D{};
}

FVector2D UMMTUnrealToolsBPLibrary::GetNormalizedMousePositionInGeometry(UObject* WorldContextObject, FGeometry Geometry) {
    return FVector2D{};
}

FVector2D UMMTUnrealToolsBPLibrary::GetMousePositionInGeometry(UObject* WorldContextObject, FGeometry Geometry) {
    return FVector2D{};
}

bool UMMTUnrealToolsBPLibrary::FindGameIniEntry(const FString& Section, const FString& Key, FString& FoundValue) {
    return false;
}

int32 UMMTUnrealToolsBPLibrary::ConstructIntegerBitwise(const TArray<bool>& BitConditions) {
    return 0;
}


