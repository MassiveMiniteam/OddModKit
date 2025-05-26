#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "SimulationActorComponent.h"
#include "DropInventoryOnCellEnter_EventDelegate.h"
#include "DropInventoryOnCellEnterComponent.generated.h"

class UBiomeCellInstance;
class UBiomeTrackerSimulationComponent;
class UPositionSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UDropInventoryOnCellEnterComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDropInventoryOnCellEnter_Event OnInventoryDropped;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBiomeTrackerSimulationComponent* BiomeTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPositionSimulationComponent* PlayerPositionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag CellTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint LastBiomePosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bPlayerIsInTaggedCell;
    
public:
    UDropInventoryOnCellEnterComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void Update();
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerPositionChanged(UPositionSimulationComponent* PositionComponent, FIntVector LastPosition);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerExitTaggedCell();
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerEnterTaggedCell();
    
    UFUNCTION(BlueprintCallable)
    void OnCellChanged(UBiomeTrackerSimulationComponent* Component, UBiomeCellInstance* CellInstance);
    
    UFUNCTION(BlueprintCallable)
    void DropInventoryToLastCellPosition();
    
};

