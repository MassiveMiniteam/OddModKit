#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "ItemAnimationPresentationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UItemAnimationPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
    UItemAnimationPresentationComponent(const FObjectInitializer& ObjectInitializer);

};

