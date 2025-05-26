#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BiomeGenerator.h"
#include "SpawnInGridActorEntry.h"
#include "SpawnInGridBiomeGenerator.generated.h"

UCLASS(Blueprintable)
class LOC_API USpawnInGridBiomeGenerator : public UBiomeGenerator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GridSpacing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxDistanceToCenter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint HeightRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSpawnInGridActorEntry> SpawnActorEntries;
    
public:
    USpawnInGridBiomeGenerator();

};

