#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "GlobalAITrackerEvent_Actor_StateDelegate.h"
#include "Templates/SubclassOf.h"
#include "TrackedAIData.h"
#include "GlobalAITracker.generated.h"

class AActor;
class UGlobalAITracker;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGlobalAITracker : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalAITrackerEvent_Actor_State OnTrackedNewAIData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<AActor>, FTrackedAIData> ClassToTrackedAIData;
    
    UGlobalAITracker(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static UGlobalAITracker* GetGlobalAITracker(const UObject* WorldContext);
    
};

