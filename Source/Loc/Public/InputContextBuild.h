#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "BuildContexGridObjectEventDelegate.h"
#include "BuildContextEventDelegate.h"
#include "GridObjectPlacementResult.h"
#include "InputContext.h"
#include "Templates/SubclassOf.h"
#include "InputContextBuild.generated.h"

class AActor;
class AGridHighlightHandler;
class AGridObject;
class ALocPlayerController;
class APresentationActor;
class ATileIndicator;
class UConstructableConfig;
class UInputActionData;
class UInputContextConstructionToolsCursor;
class UInputContextConstructionToolsGamepadMovement;
class UInputContextSubsystem;
class UInputDeviceMapping;
class UMaterialAdjustPresentationComponent;
class UMaterialInterface;
class UStaticMesh;
class UVisibilityStatePresentationComponent;

UCLASS(Blueprintable)
class LOC_API UInputContextBuild : public UInputContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCloseAfterPlacement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APresentationActor* PresentationPreviewActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGridObject* OriginalGridObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConstructableConfig* ConstructableConfig;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBuildContexGridObjectEvent GridObjectPlacedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBuildContextEvent InputContextCancelledEvent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputActionPlace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputActionRotateRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputActionCancel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInputActionData*> ConsumeInputActions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntVector CurrentSnappedPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PreviousPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint PreviousGridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsRelocating;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWaitForPlacementCommand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UInputContext> BaseInputContextClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> GridIndicatorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ATileIndicator> TileIndicatorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> CursorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* GridPlacementRuleIndicatorMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* GridPlacementRuleIndicatorMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextSubsystem* InputContextSubsystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextConstructionToolsCursor* CursorInputContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UInputContextConstructionToolsGamepadMovement> GamepadMovementInputContextClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextConstructionToolsGamepadMovement* GamepadMovementInputContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGridObject* SimulationObjectDefault;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGridHighlightHandler* GridHighlightHandler;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, ATileIndicator*> CoordinatesToTileIndicators;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UVisibilityStatePresentationComponent> VisibilityStatePresentationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UMaterialAdjustPresentationComponent> MaterialAdjustPresentationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGridObject* PreviousBuiltGridObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> CurrentErrorMessages;
    
public:
    UInputContextBuild();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TryPlaceObject();
    
public:
    UFUNCTION(BlueprintCallable)
    void SetPreviousBuiltGridObject(AGridObject* InPreviousBuiltGridObject);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RotateObject(float Rotation);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PathHighlightChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnInputRotateRight(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnInputPlace(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnInputDeviceChanged(UInputDeviceMapping* InputDevice);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnInputCancel(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnClearInputAction(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWaitingForPlacementCommand();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGridObjectPlacementResult GetPlacementResultCopy();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanBePlaced();
    
};

