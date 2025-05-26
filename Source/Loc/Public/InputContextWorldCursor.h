#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InputContext.h"
#include "InputContextWorldCursor.generated.h"

class AActor;
class ALocPlayerController;
class AWorldCursor;
class UInputActionData;

UCLASS(Blueprintable)
class LOC_API UInputContextWorldCursor : public UInputContext {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxCursorDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CursorSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CachedAxisInput_LeftStick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CachedAxisInput_RightStick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CursorLocalPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CursorLocalPositionUnclamped;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* MoveXAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* MoveYAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* MoveRightStickXAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* MoveRightStickYAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* LockTargetAction;
    
public:
    UInputContextWorldCursor();

private:
    UFUNCTION(BlueprintCallable)
    void OnMoveYInput(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnMoveXInput(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnMoveRightStickYInput(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnMoveRightStickXInput(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnLockTargetAction(UInputActionData* InputAction, ALocPlayerController* Player);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInputActionLockOnTarget();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ModifyAxisInputs_BP(float DeltaTime, FVector& ModifiedLeftStickInput, FVector& ModifiedRightStickInput);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLockedOn() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    AActor* GetLockedActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    AWorldCursor* GetCursor() const;
    
};

