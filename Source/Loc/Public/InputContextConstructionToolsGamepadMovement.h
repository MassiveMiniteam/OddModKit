#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InputContext.h"
#include "InputContextConstructionToolsGamepadMovement.generated.h"

class ALocPlayerController;
class UCurveFloat;
class UInputActionData;
class UInputContextConstructionToolsCursor;
class UInputContextSubsystem;
class USpringArmComponent;

UCLASS(Abstract, Blueprintable)
class LOC_API UInputContextConstructionToolsGamepadMovement : public UInputContext {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextConstructionToolsCursor* CursorInputContext;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_AxisX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_AxisY;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_ToggleMovement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* ZoomCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D FlexibleGamepadCursorRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ControllerMoveSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextSubsystem* InputContextSubsystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpringArmComponent* SpringArmComponent;
    
public:
    UInputContextConstructionToolsGamepadMovement();

private:
    UFUNCTION(BlueprintCallable)
    void OnMoveYAxis(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnMoveXAxis(UInputActionData* InputAction, ALocPlayerController* Player);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnMovementModeChanged();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnInputAction_ToggleMovement(UInputActionData* InputAction, ALocPlayerController* Player);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAllowCharacterMovementForController() const;
    
};

