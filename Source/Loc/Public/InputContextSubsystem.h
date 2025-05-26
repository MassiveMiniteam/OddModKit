#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/InputSettings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameFramework/PlayerInput.h"
#include "ActiveInputDeviceChangedDelegate.h"
#include "EBranchInputActioKeyState.h"
#include "EInputDeviceType.h"
#include "InputContextSubsystem_EventDelegate.h"
#include "Templates/SubclassOf.h"
#include "InputContextSubsystem.generated.h"

class IInputReceiver;
class UInputReceiver;
class UInputActionData;
class UInputContainer;
class UInputContext;
class UInputDefaultActionMapping;
class UInputDeviceMapping;
class UNavUserWidget;
class UObject;
class UObjectLibrary;

/** Supported input device. */
UENUM(BlueprintType)
enum class ESwitcherooInputDevice : uint8
{
    /** Keyboard/mouse combo. */
    KeyboardMouse = 0 UMETA(DisplayName = "Keyboard / Mouse"),

    /** Gamepad. */
    Gamepad = 1,
};

UCLASS(Blueprintable)
class LOC_API UInputContextSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInputContainer*> ContainerStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInputContainer*> ContainerToAdd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInputContainer*> ContainerToRemove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInputActionData*> ClearPressedInputStateQueue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInputActionData*> DurationInputActions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInputActionData*> DurationClearInputActions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInputDeviceMapping*> InputDeviceMappings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObjectLibrary* InputActionLibrary;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasFocus;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInputContextSubsystem_Event OnContextStackChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TScriptInterface<IInputReceiver>> Receivers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInputActionData*> RegisteredInputActions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInputActionData*> SetPressedInputStateQueue;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActiveInputDeviceChanged OnInputDeviceChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputDeviceMapping* ActiveDeviceMapping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInputDeviceType CurrentGamepadDevice;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputDefaultActionMapping* DefaultActionMapping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector WorldMousePosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ScreenMousePosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInputEnabled;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLastInputEnabled;
    
public:
    UInputContextSubsystem();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void UpdateInputAxisDataState(const UObject* WorldContext, float AxisValue, UInputActionData* Data);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void UpdateInputAxesWithKey(const UObject* WorldContext, float AxisValue, FInputActionKeyMapping Key);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void UpdateInputActionsWithKey(const UObject* WorldContext, EBranchInputActioKeyState InKeyState, FInputActionKeyMapping Key);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void UpdateInputActionDataState(const UObject* WorldContext, EBranchInputActioKeyState InKeyState, UInputActionData* Data);
    
    UFUNCTION(BlueprintCallable)
    void UpdateActiveInputDeviceMapping(UInputDeviceMapping* Mapping);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void Tick(const UObject* WorldContext, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    void SetUsedByRadialMenuAll(UInputActionData* Data, bool bState, const UObject* ConsumerContext);
    
    UFUNCTION(BlueprintCallable)
    void SetUsedAllWithEqualKey(UInputActionData* Data, const UObject* ConsumerContext, bool bWithoutMod);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentGamepadDevice(EInputDeviceType DeviceType);
    
    UFUNCTION(BlueprintCallable)
    void RemoveReceiver(TScriptInterface<IInputReceiver> Receiver);
    
    UFUNCTION(BlueprintCallable)
    void RegisterInputAction(UInputActionData* Data);
    
    UFUNCTION(BlueprintCallable)
    UInputContainer* PushSingleInputContext(UInputContext* Context);
    
    UFUNCTION(BlueprintCallable)
    void PushInputContainerToTop(UInputContainer* Container);
    
    UFUNCTION(BlueprintCallable)
    void PushInputContainer(UInputContainer* Container);
    
    UFUNCTION(BlueprintCallable)
    void PopInputContainer(UInputContainer* Container);
    
    UFUNCTION(BlueprintCallable)
    void PopAllInputContainers(bool bForce);
    
    UFUNCTION(BlueprintCallable)
    void OnWindowFocusChanged(bool bIsFocused);
    
    UFUNCTION(BlueprintCallable)
    void OnModsChanged();
    
    UFUNCTION(BlueprintCallable)
    void OnDetectedInputDeviceChanged(ESwitcherooInputDevice Device);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool IsShiftPressed(const UObject* WorldContext) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool IsCtrlPressed(const UObject* WorldContext) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsContextOnTheStack(const UInputContext* Context) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsContainerOnTheStack(const UInputContainer* Container) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAxisConsumedByRadialMenu(FInputActionKeyMapping Axis);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool IsAltPressed(const UObject* WorldContext) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasUIInputContextWithWidgetType(TSubclassOf<UNavUserWidget> WidgetClass, bool bSearchWholeWidgetTree);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasUIInputContextWithAnyOfTheseWidgets(TArray<TSubclassOf<UNavUserWidget>> WidgetClasses, bool bSearchWholeWidgetTree);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasMouseKeyboardInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasControllerInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool HasActiveInputDeviceFeatureSupport(const UObject* WorldContext, TEnumAsByte<EHardwareDeviceSupportedFeatures::Type> Feature);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool HasActiveInputDeviceAudioBasedVibrationSupport(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasActiveContextOfType(TSubclassOf<UInputContext> ContextType);
    
    UFUNCTION(BlueprintCallable)
    FString GetRemappingSummary();
    
    UFUNCTION(BlueprintCallable)
    EInputDeviceType GetPlatformDefaultGamepadDevice();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UNavUserWidget* GetNavUserWidgetOfTypeFromStack(TSubclassOf<UNavUserWidget> WidgetType, bool& bResult);
    
    UFUNCTION(BlueprintCallable)
    UInputDeviceMapping* GetInputDeviceMapping(EInputDeviceType Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetHasFocus() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputContainer* GetCurrentTopContainer() const;
    
    UFUNCTION(BlueprintCallable)
    EInputDeviceType GetCurrentGamepadDevice();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputContext* GetContextOfType_ConsiderInheritance(TSubclassOf<UInputContext> ContextType, const UInputContext* IgnoreContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputContext* GetContextOfType(TSubclassOf<UInputContext> ContextType, bool& bSuccess, UInputContext* IgnoreContext);
    
    UFUNCTION(BlueprintCallable)
    void CallOnActiveInputDeviceChanged();
    
    UFUNCTION(BlueprintCallable)
    void AddReceiver(TScriptInterface<IInputReceiver> Receiver);
    
};

