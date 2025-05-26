#pragma once
#include "CoreMinimal.h"
#include "TrackedLootData.generated.h"

class UItemConfig;

USTRUCT(BlueprintType)
struct FTrackedLootData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UItemConfig*> DroppedItems;
    
    LOC_API FTrackedLootData();
};

