#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CopyToolUseable.h"
#include "EPathAddOnAmountCompareRule.h"
#include "PathAddOnSimulationComponent.h"
#include "PathAddOn_AmountFilterEventDelegate.h"
#include "PathAddOn_PassIfCarriedAmountMatches_SimulationComponent.generated.h"

class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPathAddOn_PassIfCarriedAmountMatches_SimulationComponent : public UPathAddOnSimulationComponent, public ICopyToolUseable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPathAddOn_AmountFilterEvent OnCompareModeChanged;
    
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FInt32Interval MinMaxValues;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EPathAddOnAmountCompareRule CompareRule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStatsComponent* StatsComponent;
    
public:
    UPathAddOn_PassIfCarriedAmountMatches_SimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void SetCompareRule(EPathAddOnAmountCompareRule ModeIn);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EPathAddOnAmountCompareRule GetCompareRule() const;
    

    // Fix for true pure virtual functions not being implemented
};

