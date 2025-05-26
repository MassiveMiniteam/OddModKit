#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BiomeGenerator.h"
#include "SpawnObjectEntry.h"
#include "SpawnObjectsBiomeGenerator.generated.h"

class AGridObject;

UCLASS(Blueprintable)
class LOC_API USpawnObjectsBiomeGenerator : public UBiomeGenerator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AGridObject> CenterGridObjectClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CenterGridObjectRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSpawnObjectEntry> SpawnObjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint CenterPosition;
    
public:
    USpawnObjectsBiomeGenerator();

};

