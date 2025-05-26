#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Templates/SubclassOf.h"
#include "BuildToolAssignable.generated.h"

class UBuildToolPresetExecutionStrategy;
class UObject;
class UTexture2D;

UINTERFACE(BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class LOC_API UBuildToolAssignable : public UInterface {
    GENERATED_BODY()
};

class LOC_API IBuildToolAssignable : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    virtual bool IsAssigningToPresetBarPossible(UObject* WorldContext) PURE_VIRTUAL(IsAssigningToPresetBarPossible, return false;);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    virtual void HandleExecutionStrategy(UObject* WorldContext) PURE_VIRTUAL(HandleExecutionStrategy,);
    
    UFUNCTION(BlueprintCallable)
    virtual TSubclassOf<UBuildToolPresetExecutionStrategy> GetBuildToolExecutionStrategy() PURE_VIRTUAL(GetBuildToolExecutionStrategy, return NULL;);
    
    UFUNCTION(BlueprintCallable)
    virtual TSoftObjectPtr<UTexture2D> GetBuildToolAssignableIcon() PURE_VIRTUAL(GetBuildToolAssignableIcon, return NULL;);
    
};

