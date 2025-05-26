#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ETerraformHeightType.h"
#include "TerraformPosition.generated.h"

USTRUCT(BlueprintType)
struct FTerraformPosition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint GridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ETerraformHeightType HeightType;
    
    LOC_API FTerraformPosition();
};

