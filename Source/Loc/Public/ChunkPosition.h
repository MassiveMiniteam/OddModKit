#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ChunkPosition.generated.h"

USTRUCT(BlueprintType)
struct FChunkPosition : public FIntPoint {
    GENERATED_BODY()
public:
    LOC_API FChunkPosition();
};
FORCEINLINE uint32 GetTypeHash(const FChunkPosition) { return 0; }

