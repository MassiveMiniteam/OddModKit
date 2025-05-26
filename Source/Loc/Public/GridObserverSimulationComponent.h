#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SimulationActorComponent.h"
#include "GridObserverSimulationComponent.generated.h"

class AGridObject;
class UPositionSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGridObserverSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> StoredRelativeTargetPositions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPositionSimulationComponent* PositionComponent;
    
public:
    UGridObserverSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnRelocated(UPositionSimulationComponent* PositionSimulationComponent, FIntVector LastPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnGridCellChanged(AGridObject* GridObject, FIntPoint GridPosition);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FIntPoint> GetTargetCells() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FIntPoint> GetStoredRelativeTargetCells() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<FIntPoint> GetRelativeTargetCells();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FIntPoint> ConvertCellsToPositionAndRotation(FIntPoint GridPos, int32 Rotation, const TArray<FIntPoint>& CellsToConvert) const;
    
};

