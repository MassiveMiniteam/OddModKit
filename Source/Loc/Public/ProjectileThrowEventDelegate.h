#pragma once
#include "CoreMinimal.h"
#include "ProjectilePresentationParameters.h"
#include "ProjectileThrowEventDelegate.generated.h"

class UProjectilePresentationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FProjectileThrowEvent, UProjectilePresentationComponent*, ProjectilePresentation, FProjectilePresentationParameters, Params);

