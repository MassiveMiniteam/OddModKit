#pragma once
#include "CoreMinimal.h"
#include "PlayerPUIDPair.generated.h"

class APlayerState;

USTRUCT(BlueprintType)
struct FPlayerPUIDPair {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APlayerState* PlayerState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PUID;
    
    LOCCORE_API FPlayerPUIDPair();
};

