#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IntPointToConstructableConfig.generated.h"

class UConstructableConfig;

USTRUCT(BlueprintType)
struct FIntPointToConstructableConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint IntPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UConstructableConfig* ConstructableConfig;
    
    LOC_API FIntPointToConstructableConfig();
};

