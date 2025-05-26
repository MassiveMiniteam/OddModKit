#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "InputContext.h"
#include "InputContextDragPlacementEventDelegate.h"
#include "Templates/SubclassOf.h"
#include "InputContextDragPlacement.generated.h"

class AActor;
class ADragPlaceablePresentationActor;
class ALocPlayerController;
class UActorPoolManager;
class UBuildContextUI;
class UConstructableConfig;
class UGridNetworkManagerSubsystem;
class UHighlightPresentationComponent;
class UInputActionData;
class UInputContextConstructionToolsCursor;
class UInputContextConstructionToolsGamepadMovement;

UCLASS(Blueprintable)
class LOC_API UInputContextDragPlacement : public UInputContext {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint PreviousHoveredCell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsDragging;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsInDestructMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector StartVectorPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint StartGridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint StartDragDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint ObjectSize;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInputContextDragPlacementEvent OnPressedNext;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInputContextDragPlacementEvent OnPressedPrevious;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInputContextDragPlacementEvent OnContextCancelled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> DragPlaceableActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCursorAndIndicatorsShouldBeVisible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextConstructionToolsCursor* CursorInputContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* CurrentTileIndicator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActorPoolManager* PreviewPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActorPoolManager* InvalidTilePreviewPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> InvalidTilePreviewActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHighlightPresentationComponent* HighlightPresentationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBuildContextUI* CostUI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ADragPlaceablePresentationActor*> ActorsAboutToDelete;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGridNetworkManagerSubsystem> GridNetworkSubsystemClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> IndicatorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> CursorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UBuildContextUI> CostUIType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> GridIndicatorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConstructableConfig* ConstructableConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsGridCellsDirty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UInputContext> GamepadMovementInputContextClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextConstructionToolsGamepadMovement* GamepadMovementInputContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* BuildPlaceInputAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* CancelInputAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* DestroyInputAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* NextObjectInputAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* PrevObjectInputAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNeedsFirstTickSetup;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, bool> CanBePlacedCache;
    
public:
    UInputContextDragPlacement();

protected:
    UFUNCTION(BlueprintCallable)
    void UpdatePreview();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateHighlightEffect();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void TryPlaceObject();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlacementResultEvent(bool bSuccess);
    
    UFUNCTION(BlueprintCallable)
    void OnPrevObjectIndex(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnNextObjectIndex(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnNewTileHoveredEvent();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnLeftDestructMode();
    
    UFUNCTION(BlueprintCallable)
    void OnGridCellChanged(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEnteredDestructMode();
    
    UFUNCTION(BlueprintCallable)
    void OnDestroyInput(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnCancelInput(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnBuildPlaceInput(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FIntPoint> GetValidTilePositionsToTarget(bool bIgnoreCost);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FIntPoint> GetTilesInRectangularDragArea() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FIntPoint> GetTilePositionsToTarget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FIntPoint> GetInvalidTilePositionsToTarget();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DestroyConnectorTileEvent(int32 Amount);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanPlaceObjectAt(FIntPoint position) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanPayForObjectsAmount(int32 ObjectsAmount) const;
    
};

