#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AsyncEventDelegate.h"
#include "LoadBalancerSubsystem.generated.h"

class UObject;

UCLASS(Blueprintable)
class LOCCORE_API ULoadBalancerSubsystem : public UTickableWorldSubsystem {
    GENERATED_BODY()
public:
    ULoadBalancerSubsystem();

    UFUNCTION(BlueprintCallable)
    void SetLoadAllBlocking(bool bInLoadAllBlocking);
    
    UFUNCTION(BlueprintCallable)
    static UClass* LoadClassBlockingNoFlush(const UObject* WorldObjectContext, TSoftClassPtr<UObject> SoftClassPtr);
    
    UFUNCTION(BlueprintCallable)
    static UObject* LoadAssetBlockingNoFlush(const UObject* WorldObjectContext, TSoftObjectPtr<UObject> SoftObjectPtr);
    
    UFUNCTION(BlueprintCallable)
    static void LoadAssetAsync(UObject* WorldObjectContext, TSoftObjectPtr<UObject> SoftObjectPtr, UObject* customData, const FAsyncEvent& Callback);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetLoadAllBlocking() const;
    
    UFUNCTION(BlueprintCallable)
    void AsyncLoad(TSoftObjectPtr<UObject> SoftObjectPtr, UObject* customData, const FAsyncEvent& Callback);
    
};

