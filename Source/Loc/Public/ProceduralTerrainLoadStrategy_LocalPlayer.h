#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProceduralTerrainLoadStrategy.h"
#include "ProceduralTerrainLoadStrategy_LocalPlayer.generated.h"

UCLASS(Blueprintable)
class UProceduralTerrainLoadStrategy_LocalPlayer : public UProceduralTerrainLoadStrategy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint LoadSize;
    
    UProceduralTerrainLoadStrategy_LocalPlayer();

};

