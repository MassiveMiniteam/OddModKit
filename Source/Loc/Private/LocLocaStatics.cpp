#include "LocLocaStatics.h"

ULocLocaStatics::ULocLocaStatics() {
}

FText ULocLocaStatics::UpdateStringTableEntry(const FSoftObjectPath& StringTablePath, const FString& Key, const FString& Value) {
    return FText::GetEmpty();
}

void ULocLocaStatics::SetStringTableEntry(const FString& TableName, const FString& Key, const FString& Value, const FString& Path) {
}

void ULocLocaStatics::SaveStringTableRef(const FSoftObjectPath& StringTablePath) {
}

void ULocLocaStatics::SaveStringTable(const FString& TableName, const FString& Path) {
}

void ULocLocaStatics::RemoveKeyFromStringTable(const FSoftObjectPath& StringTablePath, const FString& Key) {
}

bool ULocLocaStatics::ImportStringTableToPathSimple(const FString& FilePath, const FSoftObjectPath& StringTablePath) {
    return false;
}

bool ULocLocaStatics::ImportCSVToStringTable(const FString& InFilename, const FSoftObjectPath& StringTablePath) {
    return false;
}

bool ULocLocaStatics::ExportStringTableToPathSimple(const FString& FilePath, const FSoftObjectPath& StringTablePath) {
    return false;
}

bool ULocLocaStatics::ExportStringTableToPath(const FString& FilePath, const FSoftObjectPath& StringTablePath, const TArray<FString>& LimitToKeys) {
    return false;
}

void ULocLocaStatics::ApplyEnglishLocalizationToStringTable(const FSoftObjectPath& StringTablePath) {
}


