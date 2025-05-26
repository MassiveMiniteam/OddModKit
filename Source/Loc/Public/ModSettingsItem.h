#pragma once
#include "CoreMinimal.h"
#include "ModSettingsItem.generated.h"

USTRUCT(BlueprintType)
struct FModSettingsItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString ModId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString ModVersion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<uint8> Bytes;
    
    LOC_API FModSettingsItem();
};

