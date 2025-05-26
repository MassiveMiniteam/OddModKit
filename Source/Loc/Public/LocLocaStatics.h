#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LocLocaStatics.generated.h"

UCLASS(Blueprintable)
class LOC_API ULocLocaStatics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    ULocLocaStatics();

    UFUNCTION(BlueprintCallable)
    static FText UpdateStringTableEntry(const FSoftObjectPath& StringTablePath, const FString& Key, const FString& Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetStringTableEntry(const FString& TableName, const FString& Key, const FString& Value, const FString& Path);
    
    UFUNCTION(BlueprintCallable)
    static void SaveStringTableRef(const FSoftObjectPath& StringTablePath);
    
    UFUNCTION(BlueprintCallable)
    static void SaveStringTable(const FString& TableName, const FString& Path);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveKeyFromStringTable(const FSoftObjectPath& StringTablePath, const FString& Key);
    
    UFUNCTION(BlueprintCallable)
    bool ImportStringTableToPathSimple(const FString& FilePath, const FSoftObjectPath& StringTablePath);
    
    UFUNCTION(BlueprintCallable)
    static bool ImportCSVToStringTable(const FString& InFilename, const FSoftObjectPath& StringTablePath);
    
    UFUNCTION(BlueprintCallable)
    static bool ExportStringTableToPathSimple(const FString& FilePath, const FSoftObjectPath& StringTablePath);
    
    UFUNCTION(BlueprintCallable)
    static bool ExportStringTableToPath(const FString& FilePath, const FSoftObjectPath& StringTablePath, const TArray<FString>& LimitToKeys);
    
    UFUNCTION(BlueprintCallable)
    static void ApplyEnglishLocalizationToStringTable(const FSoftObjectPath& StringTablePath);
    
};

