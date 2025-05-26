#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "ForceFieldPresentationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UForceFieldPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
    UForceFieldPresentationComponent(const FObjectInitializer& ObjectInitializer);

};

