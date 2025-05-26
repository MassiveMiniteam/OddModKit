#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "Templates/SubclassOf.h"
#include "GameplayEffectFromUnlockableSimulationComponent.generated.h"

class UGameplayEffect;
class UStatsComponent;
class UUnlockHandlingSimulationComponent;
class UUnlockableDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGameplayEffectFromUnlockableSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UUnlockHandlingSimulationComponent> UnlockHandlingComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UUnlockableDataAsset*, TSubclassOf<UGameplayEffect>> UnlockableEffects;
    
public:
    UGameplayEffectFromUnlockableSimulationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnItemUnlocked(UUnlockableDataAsset* UnlockableDataAsset);
    
public:
    UFUNCTION(BlueprintCallable)
    void ApplyAllUnlockedEffects();
    
};

