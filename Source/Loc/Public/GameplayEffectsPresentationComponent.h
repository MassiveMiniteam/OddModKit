#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "GameplayEffectsPresentationComponent.generated.h"

class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGameplayEffectsPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IntervalBetweenSingleEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayAfterLastEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialDelay;
    
public:
    UGameplayEffectsPresentationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void VisualizeNextEffect();
    
    UFUNCTION(BlueprintCallable)
    void OnGameplayEffectsListChanged(UStatsComponent* InStatsComponent);
    
};

