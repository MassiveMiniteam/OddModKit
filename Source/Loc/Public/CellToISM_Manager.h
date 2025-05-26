#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimulationActor.h"
#include "CellISMConfig.h"
#include "CellISMRuntimeData.h"
#include "CellToISM_Manager.generated.h"

class UProceduralTerrainLoadStrategy;
class UProceduralTerrainLoadStrategy_LocalPlayer;
class UStableInstancedStaticMeshComponent;

UCLASS(Blueprintable)
class LOC_API ACellToISM_Manager : public ASimulationActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FIntPoint> PositionsLastUpdate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LoadSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DistanceForUpdate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UProceduralTerrainLoadStrategy* CurrentLoadStrategy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UProceduralTerrainLoadStrategy_LocalPlayer* LoadStrategy_AroundLocalPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, FCellISMConfig> MeshConfigByValue;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStableInstancedStaticMeshComponent*> ISMSToUpdateRenderState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<int32, UStableInstancedStaticMeshComponent*> InstancedMeshComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, FCellISMRuntimeData> SpawnedTransitionTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint LastPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsFirstTick;
    
public:
    ACellToISM_Manager(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateTileAt(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable)
    void UpdateMeshes(bool bClear);
    
    UFUNCTION(BlueprintCallable)
    void RemoveMeshAtGridPosition(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable)
    void RemoveAll();
    
    UFUNCTION(BlueprintCallable)
    void OnGridCellMeshNeedsUpdate(FIntPoint GridPosition, bool bIsHeightChange);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsDrawConditionMet(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasISMForValue(int32 ValueToCheck, FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    int32 GetValue(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    int32 GetNumCustomDataFloats() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetCustomDataFloat(int32 CustomDataIndex, FIntPoint GridPosition) const;
    
};

