#pragma once
#include "CoreMinimal.h"
#include "GlobalStatsTrackerEvent_TemperatureOnReceiverChangedDelegate.h"
#include "LocGameplaySubsystem.h"
#include "GlobalStatsTrackerSubsystem.generated.h"

UCLASS(Blueprintable)
class LOC_API UGlobalStatsTrackerSubsystem : public ULocGameplaySubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalStatsTrackerEvent_TemperatureOnReceiverChanged OnTemperatureOnReceiverChanged;
    
    UGlobalStatsTrackerSubsystem();

};

