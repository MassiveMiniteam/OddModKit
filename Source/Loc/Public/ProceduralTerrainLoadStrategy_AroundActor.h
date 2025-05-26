#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProceduralTerrainLoadStrategy.h"
#include "ProceduralTerrainLoadStrategy_AroundActor.generated.h"

class AActor;

UCLASS(Blueprintable)
class UProceduralTerrainLoadStrategy_AroundActor : public UProceduralTerrainLoadStrategy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint LoadSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Actor;
    
    UProceduralTerrainLoadStrategy_AroundActor();

};

