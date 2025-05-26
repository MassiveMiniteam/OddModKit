#pragma once
#include "CoreMinimal.h"
#include "Fixed64.h"
#include "ArrayOfCountWithTimeStamp.h"
#include "OnAgentPassed_DelegateDelegate.h"
#include "OnItemCounterChangedDelegate.h"
#include "PathAddOnSimulationComponent.h"
#include "PathAddOn_ItemThroughputMeter_SimulationComponent.generated.h"

class UItemConfig;
class USimulationTimerComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPathAddOn_ItemThroughputMeter_SimulationComponent : public UPathAddOnSimulationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAgentPassed_Delegate OnAgentPassed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnItemCounterChanged OnItemCounterChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<UItemConfig*, FArrayOfCountWithTimeStamp> ItemCounters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed64 LifeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64 KeepEntriesDuration;
    
public:
    UPathAddOn_ItemThroughputMeter_SimulationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnFilterTimerFired(USimulationTimerComponent* SimulationTimerComponent);
    
};

