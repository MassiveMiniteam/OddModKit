#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SimulationActorComponent.h"
#include "BiomeTrackerCellBiomeConfigEventDelegate.h"
#include "BiomeTrackerCellInstanceEventDelegate.h"
#include "BiomeTrackerSimulationComponent.generated.h"

class UBiomeCellInstance;
class UBiomeConfig;
class UPositionSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UBiomeTrackerSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBiomeTrackerCellInstanceEvent OnEnteredNewCellInstance;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBiomeTrackerCellBiomeConfigEvent OnEnteredBiome;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBiomeTrackerCellBiomeConfigEvent OnEnteredBiomeFirstTime;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UBiomeConfig*> VisitedBiomes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint LastCellInstancePosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UBiomeConfig* BiomeConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBiomeCellInstance* CellInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> PositionComponent;
    
public:
    UBiomeTrackerSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnGridPositionChanged(UPositionSimulationComponent* InPositionComponent, FIntVector LastPosition);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint GetLastCellPosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UBiomeCellInstance* GetCurrentBiomeInstance();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UBiomeConfig* GetCurrentBiomeConfig();
    
};

