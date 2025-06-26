#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InputContext.h"
#include "Templates/SubclassOf.h"
#include "AreaSelectionInputContext.generated.h"

class AActor;
class ALocPlayerController;
class UInputActionData;
class UInputContextConstructionToolsCursor;

UCLASS(Blueprintable)
class LOC_API UAreaSelectionInputContext : public UInputContext {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* FinishSelectionAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* CancelInputAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint PreviousHoveredCell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint StartGridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextConstructionToolsCursor* CursorInputContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAreaSelectionActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> CursorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> GridIndicatorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UInputContext> GamepadMovementInputContextClass;
    
public:
    UAreaSelectionInputContext();

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void TriggerAreaSelectionAction(const TArray<FIntPoint>& Cells);
    
    UFUNCTION(BlueprintCallable)
    void SetBindingToInputActions(bool bEnabled);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnNewCellHovered(FIntPoint Cell, FIntPoint PreviousCell);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnLeftAreaSelectionMode();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEnteredAreaSelectionMode();
    
    UFUNCTION(BlueprintCallable)
    void OnCancelInput(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnAreaSelectionAction(UInputActionData* InputAction, ALocPlayerController* Player);
    
};

