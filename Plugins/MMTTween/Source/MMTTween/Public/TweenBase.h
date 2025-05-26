#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ETweenEaseFunction.h"
#include "OnTweenStateEventDelegate.h"
#include "OnTweenUpdateEventDelegate.h"
#include "TweenBase.generated.h"

UCLASS(Blueprintable)
class MMTTWEEN_API UTweenBase : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTweenUpdateEvent OnTweenUpdate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTweenStateEvent OnTweenStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTweenStateEvent OnTweenStopped;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTweenStateEvent OnTweenCancelled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UObject> AttachToObjectWeak;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* AttachToObject;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TotalTime;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Duration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETweenEaseFunction EaseFunction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayReverse;
    
public:
    UTweenBase();

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnUpdate(float Progress);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnStop();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnStart();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnCancel();
    
};

