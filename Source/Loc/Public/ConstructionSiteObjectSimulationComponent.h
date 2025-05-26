#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "ConstructionSiteStateChanged_EventDelegate.h"
#include "ConstructionSite_EventDelegate.h"
#include "EConstructionSiteState.h"
#include "SimulationTimerComponent.h"
#include "ConstructionSiteObjectSimulationComponent.generated.h"

class UUnlockableDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UConstructionSiteObjectSimulationComponent : public USimulationTimerComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConstructionSite_Event OnConstructionSiteAssemblyStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConstructionSite_Event OnConstructionSiteAssemblyFinished;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConstructionSiteStateChanged_Event OnConstructionSiteStateChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUnlockableDataAsset* UnderConstructionUnlockable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUnlockableDataAsset* ConstructionFinishedUnlockable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldBeTargetedByMinions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed ConstructionFinishTime;
    
public:
    UConstructionSiteObjectSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void StartConstructionSiteAssembly();
    
    UFUNCTION(BlueprintCallable)
    void OnUnlock(UUnlockableDataAsset* UnlockableDataAsset);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EConstructionSiteState GetConstructionState();
    
    UFUNCTION(BlueprintCallable)
    void CompleteConstructionSiteAssembly();
    
};

