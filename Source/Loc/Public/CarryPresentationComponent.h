#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "CarryPresentationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UCarryPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
    UCarryPresentationComponent(const FObjectInitializer& ObjectInitializer);

};

