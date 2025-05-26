#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BiomeGenerator.h"
#include "RandomSpawnObjectBiomeGenerator.generated.h"

class ASimulationActor;

UCLASS(Blueprintable)
class LOC_API URandomSpawnObjectBiomeGenerator : public UBiomeGenerator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint SpawnAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RadiusFlat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ASimulationActor> ActorToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> SpawnPositions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, int32> SpawnRotations;
    
public:
    URandomSpawnObjectBiomeGenerator();

};

