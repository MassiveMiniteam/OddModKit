#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MMTPhysicsComponent.generated.h"

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MMTPHYSICSENGINE_API UMMTPhysicsComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UMMTPhysicsComponent(const FObjectInitializer& ObjectInitializer);

};

