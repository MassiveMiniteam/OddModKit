#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Fixed.h"
#include "Fixed64.h"
#include "TrainSettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class LOC_API UTrainSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed AllowedConeAngle;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64 MinDistance;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64 MaxDistance;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64 MaxAllowedSlope;
    
public:
    UTrainSettings();

};

