#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "LocCoreSavable.h"
#include "SimulationActor.h"
#include "GridPositionUpdateEventDelegate.h"
#include "ObjectRegisteredEventDelegate.h"
#include "ObjectUnregisteredEventDelegate.h"
#include "Templates/SubclassOf.h"
#include "GridObject.generated.h"

class AGridObject;
class UConstructableConfig;
class UGridPlacementRuleConfig;
class UObject;
class UPathAddOnSimulationComponent;
class UPositionSimulationComponent;
class UStatsComponent;

UCLASS(Blueprintable)
class LOC_API AGridObject : public ASimulationActor, public ILocCoreSavable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGridPositionUpdateEvent OnGridPositionUnderneathChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bShouldBeReplaced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bReplacesOtherGridObjectsIfPossible;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FObjectRegisteredEvent OnObjectRegistered;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FObjectUnregisteredEvent OnObjectUnregistered;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UConstructableConfig* ConstructableConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint ObjectSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> AdditionalCells;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FreeBorderAroundGeneration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UGridPlacementRuleConfig>> GridPlacementRuleConfigClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUpdatePlacementRuleIndicationOnlyOnce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AGridObject>> ClassesThatCanBeReplaced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 WorldMapID;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPositionSimulationComponent* PositionSimulationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsWalkable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStatsComponent* NativeCachedStatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPathAddOnSimulationComponent* NativeCachedPathAddOnSimulationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFindConstructableConfigOnStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 CurrentWalkabilityBitmask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 DefaultWalkabilityMask;
    
public:
    AGridObject(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    bool ShouldSnapToPlacementRule(const UObject* WorldContext, FIntPoint GridPosition, int32 TargetRotation, FIntVector& SnapPosition);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    bool ShouldRotateToPlacementRule(const UObject* WorldContext, FIntPoint GridPosition, int32 TargetRotation, int32& SnapRotation);
    
    UFUNCTION(BlueprintCallable)
    void SetConstructableConfig(UConstructableConfig* InConstructableConfig);
    
    UFUNCTION(BlueprintCallable)
    void RelocateGridObject(FIntVector NewCenterLocation, int32 NewRotation);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPreSetupSimulation(bool bIsLoading);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWalkable();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRotation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UPositionSimulationComponent* GetPositionSimulationComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntVector GetPosition() const;
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    TArray<FIntPoint> GetOccupyingTilesSimulationSafe(const UObject* WorldContext, FIntVector PositionOffset, int32 Rotation);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    TArray<FIntPoint> GetOccupyingTilesAdditionalOnly(const UObject* WorldContext, FIntVector position, int32 TargetRotation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntVector GetCornerPosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint GetCenterGridPosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UStatsComponent* GetCachedStatsComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UPathAddOnSimulationComponent* GetCachedPathAddOnSimulationComponent() const;
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    TArray<FIntPoint> GetAllOccupyingTiles(const UObject* WorldContext, FIntVector position, int32 TargetRotation);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    bool CanBePlaced(const UObject* WorldContext, FIntVector InCenterPosition, int32 TargetRotation, AGridObject* IgnoreGridObject, AGridObject* PreviousBuiltObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    TArray<FIntPoint> CalculateTilesInRangeForEachOccupyingTile(const UObject* WorldContext, int32 Distance);
    

    // Fix for true pure virtual functions not being implemented
    UFUNCTION()
    void OnAllSaveGameActorsLoadedAndRegistered() override PURE_VIRTUAL(OnAllSaveGameActorsLoadedAndRegistered,);
    
};

