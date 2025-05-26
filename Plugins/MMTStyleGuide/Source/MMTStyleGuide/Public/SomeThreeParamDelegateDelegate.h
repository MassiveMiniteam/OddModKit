#pragma once
#include "CoreMinimal.h"
#include "SomeThreeParamDelegateDelegate.generated.h"

class UClassDesignTemplate;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FSomeThreeParamDelegate, UClassDesignTemplate*, ClassDesignTemplateUsedAsFirstArgument, int32, Parameter1, float, Parameter2);

