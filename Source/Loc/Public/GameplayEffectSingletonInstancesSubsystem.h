#pragma once
#include "CoreMinimal.h"
#include "LocSimulationSubsystem.h"
#include "Templates/SubclassOf.h"
#include "GameplayEffectSingletonInstancesSubsystem.generated.h"

class UGameplayEffect;

UCLASS(Blueprintable)
class LOC_API UGameplayEffectSingletonInstancesSubsystem : public ULocSimulationSubsystem {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UGameplayEffect>, UGameplayEffect*> GameplayEffectInstances;
    
public:
    UGameplayEffectSingletonInstancesSubsystem();

    UFUNCTION(BlueprintCallable)
    UGameplayEffect* GetOrCreate(TSubclassOf<UGameplayEffect> Type);
    
};

