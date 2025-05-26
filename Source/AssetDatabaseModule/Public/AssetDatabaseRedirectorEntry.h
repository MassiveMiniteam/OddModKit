#pragma once
#include "CoreMinimal.h"
#include "AssetDatabaseRedirectorEntry.generated.h"

USTRUCT(BlueprintType)
struct FAssetDatabaseRedirectorEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Old;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString New;
    
    ASSETDATABASEMODULE_API FAssetDatabaseRedirectorEntry();
};

