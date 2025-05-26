#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightingManager.generated.h"

class UDirectionalLightComponent;
class ULightPresetsData;
class USkyLightComponent;

UCLASS(Blueprintable)
class LOC_API ALightingManager : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LerpDuration;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkyLightComponent* CurrentSkylightComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDirectionalLightComponent* CurrentDirectionalLightComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULightPresetsData* CurrentPresets;
    
public:
    ALightingManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void LerpNewLightPresets(UDirectionalLightComponent* DirectionalLightComponent, USkyLightComponent* SkyLightComponent, ULightPresetsData* Presets, float Duration);
    
};

