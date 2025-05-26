#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "RecentlyUnlockedDataAssetEventDelegate.h"
#include "RecentlyUnlockedListChangedEventDelegate.h"
#include "RecentlyUnlockedAssetsTrackerSimulationComponent.generated.h"

class UDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API URecentlyUnlockedAssetsTrackerSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRecentlyUnlockedListChangedEvent OnRecentlyUnlockedListChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRecentlyUnlockedDataAssetEvent OnRecentlyUnlockedDataAssetAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRecentlyUnlockedDataAssetEvent OnRecentlyMarkedAsSeen;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UDataAsset*> SeenDataAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UDataAsset*> RecentlyUnlockedAssets;
    
public:
    URecentlyUnlockedAssetsTrackerSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void RemoveRecentlyUnlockedDataAssets(TArray<UDataAsset*> DataAssets);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UDataAsset*> GetSeenDataAssets() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UDataAsset*> GetRecentlyUnlockedAssets() const;
    
    UFUNCTION(BlueprintCallable)
    void AddSeenDataAssets(TArray<UDataAsset*> DataAssets);
    
    UFUNCTION(BlueprintCallable)
    void AddRecentlyUnlockedDataAssets(TArray<UDataAsset*> DataAssets);
    
};

