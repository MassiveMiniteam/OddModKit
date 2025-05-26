#pragma once
#include "CoreMinimal.h"
#include "OnNewBiomeEffectDelegate.generated.h"

class UBiomeCellInstance;
class UCameraEffectPresentationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnNewBiomeEffect, UCameraEffectPresentationComponent*, Component, UBiomeCellInstance*, PreviousCell, UBiomeCellInstance*, CurrentCell);

