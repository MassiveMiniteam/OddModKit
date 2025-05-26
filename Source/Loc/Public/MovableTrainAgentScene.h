#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "MovableTrainAgentScene.generated.h"

class USceneComponent;

USTRUCT(BlueprintType)
struct FMovableTrainAgentScene {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference SceneComponentReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OffsetAlongSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComponent;
    
    LOC_API FMovableTrainAgentScene();
};

