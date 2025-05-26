#pragma once
#include "CoreMinimal.h"
#include "BuildContextEventDelegate.generated.h"

class UInputContextBuild;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBuildContextEvent, UInputContextBuild*, InputContext);

