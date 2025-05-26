#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InputContext.h"
#include "InputContextShootPlayerToLocation.generated.h"

class UTweenBase;

UCLASS(Blueprintable)
class LOC_API UInputContextShootPlayerToLocation : public UInputContext {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector StartLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector TargetLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Height;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Duration;
    
public:
    UInputContextShootPlayerToLocation();

protected:
    UFUNCTION(BlueprintCallable)
    void OnTweenFinished(UTweenBase* Tween);
    
    UFUNCTION(BlueprintCallable)
    void OnTweenCancelled(UTweenBase* Tween);
    
};

