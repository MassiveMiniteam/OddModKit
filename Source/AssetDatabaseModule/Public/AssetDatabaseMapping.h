#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "AssetDatabaseMapping.generated.h"

class UObject;

UCLASS(Blueprintable)
class ASSETDATABASEMODULE_API UAssetDatabaseMapping : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid Guid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UObject> Asset;
    
    UAssetDatabaseMapping();

};

