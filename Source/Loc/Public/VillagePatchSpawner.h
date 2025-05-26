#pragma once
#include "CoreMinimal.h"
#include "LocActor.h"
#include "VillagePatchSpawner.generated.h"

class ASimulationActor;
class USceneComponent;

UCLASS(Blueprintable)
class LOC_API AVillagePatchSpawner : public ALocActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneRoot;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ASimulationActor> ActorToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GenerationVersion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreOnConsole;
    
    AVillagePatchSpawner(const FObjectInitializer& ObjectInitializer);

};

