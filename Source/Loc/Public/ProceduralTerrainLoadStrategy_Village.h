#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProceduralTerrainLoadStrategy.h"
#include "ProceduralTerrainLoadStrategy_Village.generated.h"

UCLASS(Blueprintable)
class UProceduralTerrainLoadStrategy_Village : public UProceduralTerrainLoadStrategy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint LoadSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FIntPoint CachedVillageCenter;
    
    UProceduralTerrainLoadStrategy_Village();

};

