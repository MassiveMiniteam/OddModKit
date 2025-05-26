#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ConstructionsCopyData.h"
#include "InputContext.h"
#include "Templates/SubclassOf.h"
#include "InputContextCopyTool.generated.h"

class AActor;
class AGridObject;
class ALocPlayerController;
class UCopyToolMemoryPresentationComponent;
class UInputActionData;
class UInputContextConstructionToolsCursor;
class UInputContextPasteTool;

UCLASS(Blueprintable)
class LOC_API UInputContextCopyTool : public UInputContext {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextConstructionToolsCursor* CursorInputContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint PreviousHoveredCell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint StartGridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsDragging;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCopyToolMemoryPresentationComponent* CopyToolMemoryComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AGridObject*> GridObjectsHightlighted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_Confirm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_Cancel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> CursorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> GridIndicatorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UInputContext> GamepadMovementInputContextClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UInputContextPasteTool> PasteToolInputContextClass;
    
public:
    UInputContextCopyTool();

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnNewCellHovered(FIntPoint Cell, FIntPoint PreviousCell);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnLeftDragMode();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnEnteredDragMode();
    
    UFUNCTION(BlueprintCallable)
    void OnConfirm(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnCancel(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    FConstructionsCopyData GetAllCopyDataFromDragArea();
    
};

