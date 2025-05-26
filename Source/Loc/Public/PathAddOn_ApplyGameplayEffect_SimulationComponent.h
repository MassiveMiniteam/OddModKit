#pragma once
#include "CoreMinimal.h"
#include "OnPathAddonGameplayEffectAppliedDelegateDelegate.h"
#include "PathAddOnSimulationComponent.h"
#include "Templates/SubclassOf.h"
#include "PathAddOn_ApplyGameplayEffect_SimulationComponent.generated.h"

class UGameplayEffect;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPathAddOn_ApplyGameplayEffect_SimulationComponent : public UPathAddOnSimulationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPathAddonGameplayEffectAppliedDelegate OnPathAddonGameplayEffectAppliedDelegate;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyOnlyIfDirectionMatches;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyOnEntering;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayEffect> EffectClass;
    
public:
    UPathAddOn_ApplyGameplayEffect_SimulationComponent(const FObjectInitializer& ObjectInitializer);

};

