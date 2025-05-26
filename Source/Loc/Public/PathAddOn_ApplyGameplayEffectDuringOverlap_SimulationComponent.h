#pragma once
#include "CoreMinimal.h"
#include "PathAddOnSimulationComponent.h"
#include "Templates/SubclassOf.h"
#include "PathAddOn_ApplyGameplayEffectDuringOverlap_SimulationComponent.generated.h"

class UGameplayEffect;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPathAddOn_ApplyGameplayEffectDuringOverlap_SimulationComponent : public UPathAddOnSimulationComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayEffect> EffectClass;
    
public:
    UPathAddOn_ApplyGameplayEffectDuringOverlap_SimulationComponent(const FObjectInitializer& ObjectInitializer);

};

