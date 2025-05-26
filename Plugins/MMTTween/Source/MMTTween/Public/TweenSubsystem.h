#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "TweenSubsystem.generated.h"

class UTweenBase;

UCLASS(Blueprintable)
class MMTTWEEN_API UTweenSubsystem : public UTickableWorldSubsystem {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTweenBase*> StartTweens;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTweenBase*> RunningTweens;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTweenBase*> StopTweens;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTweenBase*> CancelTweens;
    
public:
    UTweenSubsystem();

    UFUNCTION(BlueprintCallable)
    void StopTween(UTweenBase* Tween);
    
    UFUNCTION(BlueprintCallable)
    void StartTween(UTweenBase* Tween);
    
    UFUNCTION(BlueprintCallable)
    void CancelTween(UTweenBase* Tween);
    
};

