#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "SubGridMovementComponentDelegateDelegate.h"
#include "SubGridMovementIsAboutToEnterNewTileDelegateDelegate.h"
#include "SubGridMovementSimulationComponent.generated.h"

class UPositionSimulationComponent;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API USubGridMovementSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> PositionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed CurrentSubGridProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint LastGridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint TargetGridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint CurrentSubGridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumSubGridPositions;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSubGridMovementComponentDelegate OnSubGridPositionChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSubGridMovementComponentDelegate OnGridPositionChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSubGridMovementIsAboutToEnterNewTileDelegate IsAboutToEnterNewTileDelegate;
    
    USubGridMovementSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool NextSubGridPositionMovesOutOfCurrentTile() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint GetTargetGridPosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumSubGridPositions() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetNextGridPositionAndSubGridPosition(FIntPoint& GridPosition, FIntPoint& SubGridPosition) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint GetLastHeading() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint GetLastGridPosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetDurationInSecondsPerSubTile() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetCurrentSubGridProgress() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint GetCurrentSubGridPosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint GetCurrentSubGridHeading() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint GetCurrentHeading() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint GetCurrentGridPosition() const;
    
};

