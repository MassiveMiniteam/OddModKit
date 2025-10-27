#pragma once
#include "CoreMinimal.h"
#include "AreaSelectionInputContext.h"
#include "Templates/SubclassOf.h"
#include "LandscapeTilingInputContext.generated.h"

class UBuildContextUI;
class UConstructableGroundTileConfig;

UCLASS(Blueprintable)
class LOC_API ULandscapeTilingInputContext : public UAreaSelectionInputContext {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBuildContextUI* CostUI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UBuildContextUI> CostUIType;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConstructableGroundTileConfig* ConstructableConfig;
    
    ULandscapeTilingInputContext();

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateCostUI();
    
};

