#pragma once
#include "CoreMinimal.h"
#include "AddActorToQueueCommand_DelegateDelegate.generated.h"

class UAddToActorQueueCommand;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAddActorToQueueCommand_Delegate, UAddToActorQueueCommand*, Command);

