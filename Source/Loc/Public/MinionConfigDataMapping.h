#pragma once
#include "CoreMinimal.h"
#include "MinionConfigDataMapping.generated.h"

class UItemMinionConfig;
class UItemStackData;

USTRUCT(BlueprintType)
struct FMinionConfigDataMapping {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UItemMinionConfig* Config;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UItemStackData* Data;
    
    LOC_API FMinionConfigDataMapping();
};
FORCEINLINE uint32 GetTypeHash(const FMinionConfigDataMapping) { return 0; }

