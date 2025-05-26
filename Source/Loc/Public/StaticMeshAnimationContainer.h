#pragma once
#include "CoreMinimal.h"
#include "AnimationContainer.h"
#include "StaticMeshAnimationItem.h"
#include "StaticMeshAnimationContainer.generated.h"

UCLASS(Blueprintable)
class LOC_API UStaticMeshAnimationContainer : public UAnimationContainer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsLooping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFinishLoopingAnimationWhenStopped;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStaticMeshAnimationItem> AnimationItems;
    
    UStaticMeshAnimationContainer();

};

