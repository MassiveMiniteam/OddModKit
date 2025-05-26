#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "OnDamageAppliedDelegate.h"
#include "OnDamageAppliedWithInstigatorDelegate.h"
#include "SingleDamageTrackData.h"
#include "Templates/SubclassOf.h"
#include "HealthSimulationComponent.generated.h"

class AActor;
class UDifficultySettingsSubsystem;
class UGameplayEffectDamage;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UHealthSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDamageApplied OnDamageApplied;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDamageAppliedWithInstigator OnDamageAppliedWithInstigator;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer TagsFromLastDamageApplication;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FSingleDamageTrackData> TrackedSingleDamageDataStack;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatsComponent;
    
public:
    UHealthSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool TryApplyDamage(TSubclassOf<UGameplayEffectDamage> DamageClass, FFixed Amount, FGameplayTagContainer Tags, AActor* Instigator);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnDifficultySettingsChanged(UDifficultySettingsSubsystem* Subsystem);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FSingleDamageTrackData> GetTrackedDamageDataStack();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetMaxHealth() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetCurrentHealthInPercent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetCurrentHealth() const;
    
};

