#include "VillagePatchSpawner.h"
#include "Components/SceneComponent.h"

AVillagePatchSpawner::AVillagePatchSpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
    this->GenerationVersion = -1;
    this->bIgnoreOnConsole = false;
}


