#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BiomeGenerator.h"
#include "SpawnQuestGiversPrototypeBiomeGenerator.generated.h"

class ASimulationActor;

UCLASS(Blueprintable)
class LOC_API USpawnQuestGiversPrototypeBiomeGenerator : public UBiomeGenerator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RadiusFlat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<ASimulationActor>> QuestGivers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> SpawnPositions;
    
public:
    USpawnQuestGiversPrototypeBiomeGenerator();

};

