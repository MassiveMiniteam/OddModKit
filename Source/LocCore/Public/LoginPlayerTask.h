#pragma once
#include "CoreMinimal.h"
#include "LoginPlayerTask.generated.h"

class APlayerController;

USTRUCT(BlueprintType)
struct FLoginPlayerTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APlayerController* NewPlayer;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 TargetFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsStramingSavegame;
    
    LOCCORE_API FLoginPlayerTask();
};

