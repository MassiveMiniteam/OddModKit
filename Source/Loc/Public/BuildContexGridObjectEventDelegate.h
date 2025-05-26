#pragma once
#include "CoreMinimal.h"
#include "BuildContexGridObjectEventDelegate.generated.h"

class AGridObject;
class UInputContextBuild;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBuildContexGridObjectEvent, UInputContextBuild*, InputContext, AGridObject*, GridObject);

