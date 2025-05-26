#include "LoadBalancerSubsystem.h"

ULoadBalancerSubsystem::ULoadBalancerSubsystem() {
}

void ULoadBalancerSubsystem::SetLoadAllBlocking(bool bInLoadAllBlocking) {
}

UClass* ULoadBalancerSubsystem::LoadClassBlockingNoFlush(const UObject* WorldObjectContext, TSoftClassPtr<UObject> SoftClassPtr) {
    return NULL;
}

UObject* ULoadBalancerSubsystem::LoadAssetBlockingNoFlush(const UObject* WorldObjectContext, TSoftObjectPtr<UObject> SoftObjectPtr) {
    return NULL;
}

void ULoadBalancerSubsystem::LoadAssetAsync(UObject* WorldObjectContext, TSoftObjectPtr<UObject> SoftObjectPtr, UObject* customData, const FAsyncEvent& Callback) {
}

bool ULoadBalancerSubsystem::GetLoadAllBlocking() const {
    return false;
}

void ULoadBalancerSubsystem::AsyncLoad(TSoftObjectPtr<UObject> SoftObjectPtr, UObject* customData, const FAsyncEvent& Callback) {
}


