#pragma once
#include "CoreMinimal.h"
#include "LocSimulationSubsystem.h"
#include "Fixed64.h"
#include "ItemTrackingData.h"
#include "OnNewItemConfigTrackedDelegateDelegate.h"
#include "SnapShotHistory.h"
#include "RecipeTrackerSubsystem.generated.h"

class UItemConfig;
class URecipeConfig;
class URecipeProcessorSimulationComponent;
class URecipeTrackerDataView;

UCLASS(Blueprintable)
class LOC_API URecipeTrackerSubsystem : public ULocSimulationSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnNewItemConfigTrackedDelegate OnNewItemConfigTrackedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FSnapShotHistory ShortHistory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FSnapShotHistory MidHistory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FSnapShotHistory LongHistory;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FItemTrackingData> Data;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed64 LifeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed64 CurrentSnapshotLifeTime;
    
public:
    URecipeTrackerSubsystem();

private:
    UFUNCTION(BlueprintCallable)
    void OnRecipeCraftedFinished(URecipeProcessorSimulationComponent* RecipeProcessorSimulationComponent, URecipeConfig* RecipeConfig);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnItemCrafted(UItemConfig* ItemConfig, int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    void OnItemConsumed(UItemConfig* ItemConfig, int32 Amount);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UItemConfig*> GetAllTrackedConfigs() const;
    
    UFUNCTION(BlueprintCallable)
    URecipeTrackerDataView* CreateDataView(UItemConfig* ItemConfig);
    
};

