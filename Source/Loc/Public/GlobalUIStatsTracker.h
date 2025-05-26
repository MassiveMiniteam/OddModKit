#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "GlobalStatsTracker_UIType_EventDelegate.h"
#include "Templates/SubclassOf.h"
#include "GlobalUIStatsTracker.generated.h"

class UGlobalUIStatsTracker;
class UNavUserWidget;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGlobalUIStatsTracker : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalStatsTracker_UIType_Event OnUIOfTypeShown;
    
    UGlobalUIStatsTracker(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnUIShown(TSubclassOf<UNavUserWidget> WidgetType);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static UGlobalUIStatsTracker* GetUIStatsTracker(const UObject* WorldContext);
    
};

