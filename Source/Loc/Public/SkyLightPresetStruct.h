#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SkyLightPresetStruct.generated.h"

class UTextureCube;

USTRUCT(BlueprintType)
struct FSkyLightPresetStruct {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    bool TurnOnSkyLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureCube* Cubemap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SourceCubemapAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CubemapResolution;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SkyDistanceThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float Intensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FColor LightColor;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCaptureEmissiveOnly;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLowerHemisphereIsBlack;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor LowerHemisphereColor;
    
    LOC_API FSkyLightPresetStruct();
};

