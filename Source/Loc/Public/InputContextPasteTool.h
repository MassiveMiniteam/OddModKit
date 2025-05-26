#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "ArrayOfIntPointToConstructionConfigs.h"
#include "ConstructionsCopyData.h"
#include "GridNetworkCopyData.h"
#include "GridObjectCopyData.h"
#include "InputContext.h"
#include "IntPointToConstructableConfig.h"
#include "ItemStack.h"
#include "Templates/SubclassOf.h"
#include "InputContextPasteTool.generated.h"

class AActor;
class AGridObject;
class ALocPlayerController;
class ATileIndicator;
class UActorPoolManager;
class UConstructableConfig;
class UGridNetworkSimulationComponent;
class UGridPlacementRuleConfig;
class UInputActionData;
class UInputContextConstructionToolsCursor;
class URecipeConfig;

UCLASS(Blueprintable)
class LOC_API UInputContextPasteTool : public UInputContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConstructionsCopyData ConstructionsCopyData;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UGridPlacementRuleConfig>> PlacementRulesToAlwaysCountAsValid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UConstructableConfig*> ConstructableRampConfigs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextConstructionToolsCursor* CursorInputContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, ATileIndicator*> CoordinatesToTileIndicators;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActorPoolManager* InvalidTilePreviewPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActorPoolManager* PastePropertiesMarkerPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UConstructableConfig*, UActorPoolManager*> DragPlaceablesPreviewPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> ValidPositions_Total;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> InvalidPositions_Total;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_Confirm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_Rotate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_Cancel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> CursorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> GridIndicatorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UInputContext> GamepadMovementInputContextClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ATileIndicator> TileIndicatorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> InvalidTilePreviewActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> PastePropertiesMarkerClass;
    
public:
    UInputContextPasteTool();

    UFUNCTION(BlueprintCallable)
    static URecipeConfig* TryGetRecipeFromCopyData(const FGridObjectCopyData& CopyData);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTryPlaceSingleCopyConfig(FGridObjectCopyData GridObjectCopyData);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTryPlaceGridNetworkCopy(FGridNetworkCopyData GridNetworkCopyData);
    
    UFUNCTION(BlueprintCallable)
    void OnRotate(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnNewTileHovered(FIntPoint GridPosition);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnCursorGridPositionChanged(UInputContextConstructionToolsCursor* InputContext, FIntPoint GridPosition);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnConfirm(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnCancel(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FArrayOfIntPointToConstructionConfigs> GetValidTilePositionsToTargetInCoherentSegments(TArray<FIntPointToConstructableConfig> TilesToTarget, TSubclassOf<UGridNetworkSimulationComponent> GridNetworkType) const;
    
public:
    UFUNCTION(BlueprintCallable)
    AGridObject* FindGridObjectToCopyPropertiesFrom(FGridObjectCopyData GOCopyData, FVector SnappedPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntVector CalculateWorldPosition(FIntVector RelativePosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint CalculateWorldGridPosition(FIntPoint RelativeGridPosition) const;
    
    UFUNCTION(BlueprintCallable)
    TArray<FItemStack> CalculateOptionalCosts();
    
    UFUNCTION(BlueprintCallable)
    TMap<UConstructableConfig*, int32> CalculateCountPerDragPlaceable();
    
    UFUNCTION(BlueprintCallable)
    TMap<UConstructableConfig*, int32> CalculateCountPerConstructable();
    
    UFUNCTION(BlueprintCallable)
    TArray<FItemStack> CalculateCosts();
    
};

