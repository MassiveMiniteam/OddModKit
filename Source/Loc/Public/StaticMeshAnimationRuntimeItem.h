#pragma once
#include "CoreMinimal.h"
#include "StaticMeshAnimationRuntimeItem.generated.h"

class UAudioComponent;
class USceneComponent;
class UStaticMeshAnimationContainer;

USTRUCT(BlueprintType)
struct FStaticMeshAnimationRuntimeItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TargetItemIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStaticMeshAnimationContainer> TargetStaticMeshContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeLastFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Duration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneComponent> TargetSceneComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAudioComponent*> LoopingAudioComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStopAnimationWhenFinished;
    
    LOC_API FStaticMeshAnimationRuntimeItem();
};

