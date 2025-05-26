#pragma once
#include "CoreMinimal.h"
#include "AddActorToSlotsCommand_DelegateDelegate.generated.h"

class UAddToActorToSlotsCommand;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAddActorToSlotsCommand_Delegate, UAddToActorToSlotsCommand*, Command);

