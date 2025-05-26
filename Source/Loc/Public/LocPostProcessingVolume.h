#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LocPostProcessingVolume.generated.h"

class ULightPresetsData;

UCLASS(Blueprintable)
class LOC_API ALocPostProcessingVolume : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentWeight;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULightPresetsData* LightPreset;
    
public:
    ALocPostProcessingVolume(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetWeight(float Weight);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetWeight(float Weight);
    
};

