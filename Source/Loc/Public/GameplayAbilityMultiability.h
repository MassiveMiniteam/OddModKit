#pragma once
#include "CoreMinimal.h"
#include "GameplayAbility.h"
#include "Templates/SubclassOf.h"
#include "GameplayAbilityMultiability.generated.h"

class UStatsComponent;

UCLASS(Blueprintable)
class LOC_API UGameplayAbilityMultiability : public UGameplayAbility {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UGameplayAbility* ActiveAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayAbility> NextAbilityClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 AbilityCounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UGameplayAbility>> SubAbilityClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatsComponent;
    
    UGameplayAbilityMultiability();

protected:
    UFUNCTION(BlueprintCallable)
    void OnActiveAbilityFinished();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UGameplayAbility> GetNextAbility() const;
    
};

