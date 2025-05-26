#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "EDestructionReason.h"
#include "LocRandom.h"
#include "Fixed64.h"
#include "BiomeCellGenerationDebugBiomeEntry.h"
#include "BiomeCellInstanceArray.h"
#include "WorldCellMetaData.h"
#include "WorldGenerator.generated.h"

class ASimulationActor;
class UBiomeCellConfig;
class UBiomeCellInstance;
class UBiomeInstance;
class UVoronoiCell;
class UVoronoiPolygon;
class UWorldGenerationConfig;

UCLASS(Blueprintable)
class LOC_API UWorldGenerator : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FWorldCellMetaData> CellMetaData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASimulationActor*> GeneratedActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorldGenerationConfig* WorldConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UVoronoiCell* StartingCell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UBiomeInstance* VillageBiomeInstance;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UVoronoiPolygon*> VoronoiDualCells;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UVoronoiCell*> VoronoiCells;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBiomeInstance*> BiomeInstances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, FBiomeCellInstanceArray> BiomeCellInstanceHashmap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UVoronoiCell*, UBiomeCellInstance*> VoronoiCellBiomeCellInstanceMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, UBiomeCellInstance*> BiomeCellInstanceIdMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UBiomeCellInstance* LastCachedInstance;
    
public:
    UWorldGenerator();

    UFUNCTION(BlueprintCallable)
    void OnSimulationActorShutDown(ASimulationActor* Actor, EDestructionReason Reason);
    
    UFUNCTION(BlueprintCallable)
    FIntVector GetWorldPositionFromNormalizedMapPosition(FVector2D NormalizedMapPosition);
    
    UFUNCTION(BlueprintCallable)
    bool GetVillageCellCenter(FIntVector& OutCenter);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UBiomeInstance* GetVillageBiomeInstance();
    
    UFUNCTION(BlueprintCallable)
    bool GetStartingCellCenter(FIntVector& OutCenter);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UVoronoiCell* GetStartingCell();
    
    UFUNCTION(BlueprintCallable)
    UBiomeCellInstance* GetRandomBiomeCellInstanceOfType(UBiomeCellConfig* Config, FLocRandom Random);
    
    UFUNCTION(BlueprintCallable)
    FVector2D GetPixelOfGridPosition(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable)
    FVector2D GetNormalizedMapPositionFromWorldPosition(FIntVector WorldPosition);
    
    UFUNCTION(BlueprintCallable)
    FVector2D GetNormalizedMapPosition(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable)
    TArray<UBiomeCellInstance*> GetNeighboursOfCell(UVoronoiCell* Cell);
    
    UFUNCTION(BlueprintCallable)
    FIntPoint GetCenterPositionForClosestBiomeWithConfig(UBiomeCellConfig* Config, bool& bSucces);
    
    UFUNCTION(BlueprintCallable)
    FString GetCellConfigDebugText();
    
    UFUNCTION(BlueprintCallable)
    TArray<FBiomeCellGenerationDebugBiomeEntry> GetCellConfigDebugInfo();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UBiomeInstance*> GetBiomeInstances();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<int32, UBiomeCellInstance*> GetBiomeCellInstanceIdMap();
    
    UFUNCTION(BlueprintCallable)
    UBiomeCellInstance* GetBiomeAt(const FIntPoint& GridPosition, FFixed64& Distance, bool bWithDistance);
    
    UFUNCTION(BlueprintCallable)
    UBiomeInstance* AddBiomeInstance(int32 BiomeSeed);
    
};

