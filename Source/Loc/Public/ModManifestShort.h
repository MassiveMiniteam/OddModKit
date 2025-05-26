#pragma once
#include "CoreMinimal.h"
#include "ModManifestShort.generated.h"

USTRUCT(BlueprintType)
struct FModManifestShort {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString Version;
    
    LOC_API FModManifestShort();
};

