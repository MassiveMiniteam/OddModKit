#pragma once
#include "CoreMinimal.h"
#include "ProceduralWorldGenerator.h"
#include "WorldMapPoint.h"
#include "WorldGenerator_PlaceAndExpandBiome.generated.h"

class UBiomeConfig;
class UProceduralGeneratorCondition;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UWorldGenerator_PlaceAndExpandBiome : public UProceduralWorldGenerator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Comment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldMapPoint Origin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LookForValidOriginCellsDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBiomeConfig* BiomeConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ExpandFrom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ExpandBy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<int32, UProceduralGeneratorCondition*> ConditionsPerDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProceduralGeneratorCondition* ConditionForAllDistances;
    
    UWorldGenerator_PlaceAndExpandBiome();

};

