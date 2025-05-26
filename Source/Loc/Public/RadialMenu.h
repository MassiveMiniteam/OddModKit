#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NavUserWidget.h"
#include "RadialMenu.generated.h"

class UInputActionData;
class UInputContextSubsystem;
class URadialBox;
class URadialMenuButton;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API URadialMenu : public UNavUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* RadialMenuSelectionHorizontalInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* RadialMenuSelectionVerticalInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* ConfirmInputAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* CancelInputAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* ToggleRadialMenuInputAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxHoldDurationToStayOnScreen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
    URadialBox* RadialBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URadialMenuButton* HoveredButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextSubsystem* InputContextSubsystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoyoteTimeOnAxisRelease;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URadialMenuButton* CoyoteButton;
    
public:
    URadialMenu();

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnToggleRadialMenuInputAction();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnRadialMenuSelectionAxisInput(FVector2D AxisInput, bool bDirectionIndicatorIsVisible);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnConfirmInputAction();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnCancelInputAction();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasInputForMouse(FVector2D TargetPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasInputForController(FVector2D Direction);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetMouseCursorPosition() const;
    
};

