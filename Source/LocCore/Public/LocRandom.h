#pragma once
#include "CoreMinimal.h"
#include "LocRandom.generated.h"

USTRUCT(BlueprintType)
struct FLocRandom {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 LastRandomNumber;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Seed;
    
public:
    LOCCORE_API FLocRandom();
};

