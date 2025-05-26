#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerInput.h"
#include "Engine/DataAsset.h"
#include "EInputDeviceType.h"
#include "EMenuShowForDevice.h"
#include "InputActionStateChangedDelegate.h"
#include "InputAxisStateChangedDelegate.h"
#include "InputPressedDurationChangedEventDelegate.h"
#include "InputActionData.generated.h"

class UInputActionData;
class UObject;

UCLASS(Blueprintable)
class LOC_API UInputActionData : public UPrimaryDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText InputActionName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInputActionKeyMapping> KeyMappings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FInputActionKeyMapping> KeyReMappings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyWhenUIClosed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDevelopmentOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsNotInDemo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMenuShowForDevice ShowForDevices;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHideInSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinPressDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWasClicked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWasPressed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsPressed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWasReleased;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AxisValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentPressDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsUsed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPressedWasConsumed;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint64 LastUsedFrameCount;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInputActionStateChanged OnInputActionStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInputAxisStateChanged OnInputAxisStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInputPressedDurationChangedEvent OnInputPressedDurationChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsUsedByRadialMenu;
    
    UInputActionData();

    UFUNCTION(BlueprintCallable)
    void SetUsedPressedForClick();
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void SetUsedByRadialMenuAll(const UObject* WorldContext, bool bState);
    
    UFUNCTION(BlueprintCallable)
    void SetUsedByRadialMenu(bool bState);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void SetUsedAllWithEqualKey(const UObject* WorldContext, const UObject* ConsumerContext, bool bWithoutMod);
    
    UFUNCTION(BlueprintCallable)
    void SetUsed(const UObject* ConsumerContext);
    
    UFUNCTION(BlueprintCallable)
    void SetUnUsed();
    
    UFUNCTION(BlueprintCallable)
    void RemoveKeyReMappingByDevice(bool GamepadKey);
    
    UFUNCTION(BlueprintCallable)
    void RemoveKeyFromKeyReMapping(FInputActionKeyMapping Key);
    
    UFUNCTION(BlueprintCallable)
    bool KeyFoundInKeyReMapping(FInputActionKeyMapping Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsVisibleFor(EInputDeviceType Device) const;
    
    UFUNCTION(BlueprintCallable)
    bool IsDefaultKeyMapping(FInputActionKeyMapping Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool InputActionsHaveCommonKeyMappingInCurrentUsed(UInputActionData* Other, bool bIsGamepad);
    
    UFUNCTION(BlueprintCallable)
    TArray<FInputActionKeyMapping> GetKeysPerDeviceAndMapping(TArray<FInputActionKeyMapping> FilterKeyMapping, bool GamepadKey);
    
    UFUNCTION(BlueprintCallable)
    bool GetIsUsed();
    
    UFUNCTION(BlueprintCallable)
    FInputActionKeyMapping GetDefaultKeyByDevice(EInputDeviceType Device);
    
    UFUNCTION(BlueprintCallable)
    TArray<FInputActionKeyMapping> GetCurrentUsedKeyMappingByDeviceType(EInputDeviceType Device);
    
    UFUNCTION(BlueprintCallable)
    TArray<FInputActionKeyMapping> GetCurrentUsedKeyMapping(bool IsGamepad);
    
    UFUNCTION(BlueprintCallable)
    bool ContainsKey(FInputActionKeyMapping Key);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void ClearInput(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable)
    void AddKeyToKeyReMapping(FInputActionKeyMapping Key);
    
};

