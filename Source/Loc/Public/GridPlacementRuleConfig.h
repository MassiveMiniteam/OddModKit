#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "GameplayTagContainer.h"
#include "PlacementRuleParameter.h"
#include "PlacementRuleResult.h"
#include "GridPlacementRuleConfig.generated.h"

class AGrid;

UCLASS(Blueprintable)
class LOC_API UGridPlacementRuleConfig : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer PlacementTags;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowRuleWhilePlacing;
    
public:
    UGridPlacementRuleConfig();

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ValidateTilesWithPreviousPlacedGridObject(UPARAM(Ref) FPlacementRuleParameter& PlacementRuleParameter, FPlacementRuleResult& Result);
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    bool ShouldSnap(const UObject* WorldContext, FIntPoint GridPosition, int32 Rotation, FIntVector& SnapPosition);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    bool ShouldRotate(const UObject* WorldContext, FIntPoint GridPosition, int32 Rotation, int32& SnapRotation);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetValidTilesFromArea(UPARAM(Ref) FPlacementRuleParameter& PlacementRuleParameter, AGrid* GridInstance, UPARAM(Ref) FPlacementRuleResult& Result);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CheckForSnap(FIntPoint GridPosition, int32 Rotation, AGrid* GridInstance, FIntVector& SnapPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CheckForRotation(FIntPoint GridPosition, int32 Rotation, AGrid* GridInstance, int32& SnapRotation);
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    bool CanBePlaced(const UObject* WorldContext, FPlacementRuleParameter& PlacementRuleParameter, FPlacementRuleResult& Result);
    
};

