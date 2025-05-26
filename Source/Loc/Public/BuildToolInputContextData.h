#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BuildToolAssignable.h"
#include "Templates/SubclassOf.h"
#include "BuildToolInputContextData.generated.h"

class UBuildToolPresetExecutionStrategy;
class UInputContext;
class UObject;
class UTexture2D;

UCLASS(Blueprintable)
class LOC_API UBuildToolInputContextData : public UDataAsset, public IBuildToolAssignable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UInputContext> InputContextType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UBuildToolPresetExecutionStrategy> BuildToolStrategy;
    
    UBuildToolInputContextData();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSoftObjectPtr<UTexture2D> GetBuildToolAssignableIcon();
    

    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    bool IsAssigningToPresetBarPossible(UObject* WorldContext) override PURE_VIRTUAL(IsAssigningToPresetBarPossible, return false;);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void HandleExecutionStrategy(UObject* WorldContext) override PURE_VIRTUAL(HandleExecutionStrategy,);
    
    UFUNCTION(BlueprintCallable)
    TSubclassOf<UBuildToolPresetExecutionStrategy> GetBuildToolExecutionStrategy() override PURE_VIRTUAL(GetBuildToolExecutionStrategy, return NULL;);
    
};

