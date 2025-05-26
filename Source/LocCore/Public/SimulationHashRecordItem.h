#pragma once
#include "CoreMinimal.h"
#include "SimulationHashRecordItem.generated.h"

USTRUCT(BlueprintType)
struct FSimulationHashRecordItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString Path;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint32 Hash;
    
    LOCCORE_API FSimulationHashRecordItem();
};

