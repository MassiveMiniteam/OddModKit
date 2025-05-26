#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DirectionalLightPresetStruct.generated.h"

USTRUCT(BlueprintType)
struct FDirectionalLightPresetStruct {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    bool TurnOnDirectionalLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float Intensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FColor LightColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float LightSourceAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float LightSourceSoftAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float ShadowAmount;
    
    LOC_API FDirectionalLightPresetStruct();
};

