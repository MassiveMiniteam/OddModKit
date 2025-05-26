#pragma once
#include "CoreMinimal.h"
#include "SomeSimpleDelegateDelegate.generated.h"

class UClassDesignTemplate;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSomeSimpleDelegate, UClassDesignTemplate*, ClassDesignTemplateUsedAsFirstArgument);

