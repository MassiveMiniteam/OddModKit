#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FixedVector.h"
#include "SimulationActorComponent.h"
#include "OnNewPositionTrackedDelegate.h"
#include "MovementTrackerSimulationComponent.generated.h"

class UPositionSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UMovementTrackerSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumMaxTrackedPositions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DistanceBetweenTrackedPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ProjectTrackedPositionsOntoLandscape;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnNewPositionTracked OnNewPositionTracked;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FIntVector> TrackedPositions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> PositionComponent;
    
public:
    UMovementTrackerSimulationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnPositionChanged(UPositionSimulationComponent* InPositionComponent, FIntVector LastPosition);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FIntVector> GetTrackedPath() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntVector GetPositionAlongTrack(int32 DistanceFromLastTrackedPoint) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixedVector GetNormalizedNormalAlongTrack(int32 DistanceFromLastTrackedPoint) const;
    
};

