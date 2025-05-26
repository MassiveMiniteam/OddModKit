#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "SimulationTimerComponent.h"
#include "Templates/SubclassOf.h"
#include "DiggableSimulationComponent.generated.h"

class UGameplayAbilityTargeting;
class UGameplayEffectDamage;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UDiggableSimulationComponent : public USimulationTimerComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed DamagetoApply;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayEffectDamage> DamageEffectClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseSpreading;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MyDamageIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayAbilityTargeting> Targeting;
    
public:
    UDiggableSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void ApplySpreadingDamage(int32 Index);
    
};

