#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EProjectileLaunchType.h"
#include "ProjectilePresentationParameters.generated.h"

class ASimulationActor;

USTRUCT(BlueprintType)
struct FProjectilePresentationParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EProjectileLaunchType LaunchType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector StartPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector TargetPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASimulationActor* TargetActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Height;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Duration;
    
    LOC_API FProjectilePresentationParameters();
};

