#pragma once
#include "CoreMinimal.h"
#include "RandomSpawnObjectBiomeGenerator.h"
#include "SpawnObjectAtBorderBiomeGenerator.generated.h"

class UBiomeCellConfig;
class UBiomeConfig;

UCLASS(Blueprintable)
class LOC_API USpawnObjectAtBorderBiomeGenerator : public URandomSpawnObjectBiomeGenerator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinDistanceToEdge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoGenerateToAnotherBiome;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBiomeConfig*> BiomesToGenerateWallsTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBiomeCellConfig*> CellsToGenerateWallsTo;
    
public:
    USpawnObjectAtBorderBiomeGenerator();

};

