#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DirectionalLightPresetStruct.h"
#include "SkyLightPresetStruct.h"
#include "LightPresetsData.generated.h"

UCLASS(Blueprintable)
class LOC_API ULightPresetsData : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightPresetStruct DirectionalLightParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightPresetStruct SkyLightParameters;
    
    ULightPresetsData();

};

