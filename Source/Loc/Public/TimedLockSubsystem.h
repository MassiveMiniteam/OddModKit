#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "GameplayTagContainer.h"
#include "TimedLockSubsystem.generated.h"

UCLASS(Blueprintable)
class LOC_API UTimedLockSubsystem : public UTickableWorldSubsystem {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, float> LockTimings;
    
public:
    UTimedLockSubsystem();

    UFUNCTION(BlueprintCallable)
    void SetLockFor(FGameplayTag Tag, float Duration);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocked(FGameplayTag Tag);
    
};

