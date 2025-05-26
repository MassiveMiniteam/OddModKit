#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BuildToolPresetExecutionStrategy.generated.h"

class IBuildToolAssignable;
class UBuildToolAssignable;

UCLASS(Abstract, Blueprintable)
class UBuildToolPresetExecutionStrategy : public UObject {
    GENERATED_BODY()
public:
    UBuildToolPresetExecutionStrategy();

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, meta=(WorldContext="WorldContext"))
    void ExecuteBuildTooldPresetEvent(UObject* WorldContext, const TScriptInterface<IBuildToolAssignable>& BuildToolAssignable);
    
};

