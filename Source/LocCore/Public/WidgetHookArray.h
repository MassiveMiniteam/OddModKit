#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "WidgetHookArray.generated.h"

class UWidgetHook;

USTRUCT(BlueprintType)
struct FWidgetHookArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UWidgetHook>> Hooks;
    
    LOCCORE_API FWidgetHookArray();
};

