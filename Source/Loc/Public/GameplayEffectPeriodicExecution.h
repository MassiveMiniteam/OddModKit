#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "FixedInterval.h"
#include "GameplayEffect.h"
#include "GameplayEffectPeriodicExecution.generated.h"

UCLASS(Abstract, Blueprintable)
class LOC_API UGameplayEffectPeriodicExecution : public UGameplayEffect {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed Period;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixedInterval InitialDelayRandom;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed ElapsedTimeCurrentPeriod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed PeriodOverride;
    
public:
    UGameplayEffectPeriodicExecution();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetCurrentPeriod() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ExecutePeriodicEffect();
    
};

