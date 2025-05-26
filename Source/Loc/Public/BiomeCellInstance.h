#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SerializedSimulationObject.h"
#include "BiomeGeneratorPriorityEntry.h"
#include "BiomeInstanceGeneratorSettings.h"
#include "ChunkPosition.h"
#include "BiomeCellInstance.generated.h"

class UBiomeCellConfig;
class UBiomeInstance;
class UCellLoaderSimulationComponent;
class UObject;
class UVoronoiCell;
class UWorldGenerator;

UCLASS(Blueprintable)
class UBiomeCellInstance : public USerializedSimulationObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorldGenerator* WorldGenerator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 CellID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 AverageHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UBiomeInstance* BiomeInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UVoronoiCell* Cell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 CellSeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FChunkPosition> ChunksOverlapping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UBiomeCellConfig* CellConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBiomeGeneratorPriorityEntry> Generators;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UObject*> AllGenerators;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FBiomeInstanceGeneratorSettings GeneratorSettings;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UCellLoaderSimulationComponent>> CellLoader;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsLoaded;
    
    UBiomeCellInstance();

    UFUNCTION(BlueprintCallable)
    FIntVector GetWorldCenterPosition();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetEdges(TArray<FIntVector>& EdgeStartPoints, TArray<FIntVector>& EdgeEndPoints);
    
};

