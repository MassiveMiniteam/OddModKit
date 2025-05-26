#pragma once
#include "CoreMinimal.h"
#include "UnitGroupWithMemberDelegateDelegate.generated.h"

class UUnitGroup;
class UUnitGroupMemberSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUnitGroupWithMemberDelegate, UUnitGroup*, Group, UUnitGroupMemberSimulationComponent*, Member);

