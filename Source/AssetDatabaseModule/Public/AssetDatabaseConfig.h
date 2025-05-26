#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "AssetDatabaseRedirectorEntry.h"
#include "AssetDatabaseConfig.generated.h"

UCLASS(Blueprintable, Config=Game)
class ASSETDATABASEMODULE_API UAssetDatabaseConfig : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAssetDatabaseRedirectorEntry> RedirectorPaths;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FString, FString> RedirectorPathMap;
    
    UAssetDatabaseConfig();

};

