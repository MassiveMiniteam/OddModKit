#pragma once
#include "CoreMinimal.h"
#include "ProceduralWorldGenerator.h"
#include "WorldGenerator_AssignStartCells.generated.h"

class UBiomeConfig;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UWorldGenerator_AssignStartCells : public UProceduralWorldGenerator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Comment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBiomeConfig* WoodlandBiomeConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBiomeConfig* VillageBiomeConfig;
    
    UWorldGenerator_AssignStartCells();

};

