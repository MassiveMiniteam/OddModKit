#pragma once
#include "CoreMinimal.h"
#include "AreaSelectionInputContext.h"
#include "LandscapeTilingInputContext.generated.h"

class UConstructableGroundTileConfig;

UCLASS(Blueprintable)
class LOC_API ULandscapeTilingInputContext : public UAreaSelectionInputContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConstructableGroundTileConfig* ConstructableConfig;
    
    ULandscapeTilingInputContext();

};

