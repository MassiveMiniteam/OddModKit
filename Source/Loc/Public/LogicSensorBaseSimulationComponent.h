#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "CopyToolUseable.h"
#include "LogicSensorTargetTilesUpdatedDelegate.h"
#include "LogicSensorBaseSimulationComponent.generated.h"

class AGridObject;
class ASimulationActor;
class ULogicOutputSimulationComponent;
class ULogicSensorFoundActorsFilterStrategy;
class UPositionSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULogicSensorBaseSimulationComponent : public USimulationActorComponent, public ICopyToolUseable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLogicSensorTargetTilesUpdated OnLogicSensorTargetTilesUpdated;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference LogicOutputComponentReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> FixedTargetPointsRelative;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed Angle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Length;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULogicSensorFoundActorsFilterStrategy*> PossibleActorFilterStrategies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ULogicOutputSimulationComponent> LogicOutputComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 DetectionStrategyIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> StoredRelativeTargetPositions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 AngleModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 LengthModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed AngleModificationMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed LengthModificationMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPositionSimulationComponent* PositionComponent;
    
public:
    ULogicSensorBaseSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnRelocated(UPositionSimulationComponent* PositionSimulationComponent, FIntVector LastPosition);
    
    UFUNCTION(BlueprintCallable)
    void OnGridCellChanged(AGridObject* GridObject, FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable)
    void InitLogicConnectionComponents();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FIntPoint> GetStoredRelativeTargetCells() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FIntPoint> GetSensorTargetCells() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASimulationActor*> FilterActorsByStrategy(TArray<ASimulationActor*> ActorsToFilter) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FIntPoint> ConvertCellsToPositionAndRotation(FIntPoint GridPos, int32 Rotation, const TArray<FIntPoint>& CellsToConvert) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FIntPoint> CalculateRelativeTargetCells() const;
    

    // Fix for true pure virtual functions not being implemented
};

