#pragma once
#include "CoreMinimal.h"
#include "GameplayAbilityTargeting.h"
#include "GameplayAbilityTargeting_SingleTarget.generated.h"

UCLASS(Blueprintable)
class UGameplayAbilityTargeting_SingleTarget : public UGameplayAbilityTargeting {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Radius;
    
public:
    UGameplayAbilityTargeting_SingleTarget();

};

