#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "OnEventTriggeredDynamicDelegate.h"
#include "OnEventTriggeredDynamicMulticastDelegate.h"
#include "EventDataAsset.generated.h"

class UEventDataAsset;

UCLASS(Blueprintable)
class LOC_API UEventDataAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnEventTriggeredDynamicMulticast OnTriggerDynamic;
    
    UEventDataAsset();

    UFUNCTION(BlueprintCallable)
    static void UnBindDataAssetEvent(UEventDataAsset* EventDataAsset, const FOnEventTriggeredDynamic& Delegate);
    
    UFUNCTION(BlueprintCallable)
    void TriggerEvent();
    
    UFUNCTION(BlueprintCallable)
    static void TriggerDataAssetEvent(UEventDataAsset* EventDataAsset);
    
    UFUNCTION(BlueprintCallable)
    void OnTriggerReset(const FString& String);
    
    UFUNCTION(BlueprintCallable)
    static void BindDataAssetEvent(UEventDataAsset* EventDataAsset, const FOnEventTriggeredDynamic& Delegate);
    
};

