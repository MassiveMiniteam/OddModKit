#pragma once
#include "CoreMinimal.h"
#include "Fixed64.h"
#include "Fixed64Vector.h"
#include "PhysicsBodyLocationEventDelegate.generated.h"

class UMMTPhysicsBodyComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FPhysicsBodyLocationEvent, UMMTPhysicsBodyComponent*, PhysicsBodyComponent, FFixed64Vector, Location, FFixed64, DeltaTime);

