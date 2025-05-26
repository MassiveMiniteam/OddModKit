#pragma once
#include "CoreMinimal.h"
#include "EventDataAsset.h"
#include "EventDataAssetStateChangeDelegate.h"
#include "EventDataAssetWithState.generated.h"

class UEventDataAssetWithState;

UCLASS(Blueprintable)
class LOC_API UEventDataAssetWithState : public UEventDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventDataAssetStateChange OnEventDataAssetStateChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bState;
    
public:
    UEventDataAssetWithState();

    UFUNCTION(BlueprintCallable)
    static void SetEventDataAssetState(UEventDataAssetWithState* EventDataAsset, bool bStateIn);
    
    UFUNCTION(BlueprintCallable)
    static bool GetEventDataAssetState(UEventDataAssetWithState* EventDataAsset);
    
};

