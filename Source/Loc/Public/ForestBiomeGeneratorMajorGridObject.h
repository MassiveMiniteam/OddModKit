#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ForestBiomeGeneratorMajorGridObject.generated.h"

class AGridObject;

USTRUCT(BlueprintType)
struct FForestBiomeGeneratorMajorGridObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AGridObject>> Actors;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntVector2 Amount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpawnRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DontGenerateTreesAroundSpawnPointInGridUnits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyWorldSettingsMultiplierToAmount;
    
    LOC_API FForestBiomeGeneratorMajorGridObject();
};

