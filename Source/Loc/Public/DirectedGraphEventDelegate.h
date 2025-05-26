#pragma once
#include "CoreMinimal.h"
#include "DirectedGraphEventDelegate.generated.h"

class UDirectedGraph;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDirectedGraphEvent, UDirectedGraph*, DirectedGraph);

