#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "Templates/SubclassOf.h"
#include "GlossaryUnlockOnDamageComponent.generated.h"

class UGameplayEffectDamage;
class UGlossaryCategoryData;
class UHealthSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGlossaryUnlockOnDamageComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGlossaryCategoryData* CachedGlossaryAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UHealthSimulationComponent> HealthComponent;
    
public:
    UGlossaryUnlockOnDamageComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnDamageApplied(TSubclassOf<UGameplayEffectDamage> Class, FFixed Amount, FGameplayTagContainer Tags);
    
};

