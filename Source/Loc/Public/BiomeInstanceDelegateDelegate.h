#pragma once
#include "CoreMinimal.h"
#include "BiomeInstanceDelegateDelegate.generated.h"

class UBiomeInstance;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBiomeInstanceDelegate, UBiomeInstance*, BiomeInstance);

