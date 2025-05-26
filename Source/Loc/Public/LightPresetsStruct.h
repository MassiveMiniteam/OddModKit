#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DirectionalLightPresetStruct.h"
#include "SkyLightPresetStruct.h"
#include "LightPresetsStruct.generated.h"

USTRUCT(BlueprintType)
struct FLightPresetsStruct {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag LightTypeTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsSeasonalLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightPresetStruct DirectionalLightPreset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightPresetStruct SkyLightPreset;
    
    LOC_API FLightPresetsStruct();
};

