#pragma once
#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "Framework/Commands/InputChord.h"
#include "Styling/SlateTypes.h"
#include "Layout/Margin.h"
#include "Styling/SlateTypes.h"
#include "Components/SlateWrapperTypes.h"
#include "Components/Widget.h"
#include "LocInputKeySelector.generated.h"

UCLASS(Blueprintable)
class LOC_API ULocInputKeySelector : public UWidget {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKeySelected, FInputChord, SelectedKey);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnIsSelectingKeyChanged);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnButtonLostFocus);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonStyle WidgetStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTextBlockStyle TextStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInputChord SelectedKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMargin Margin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText KeySelectionText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText NoKeySpecifiedText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowModifierKeys;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowGamepadKeys;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FKey> EscapeKeys;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnKeySelected OnKeySelected;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnIsSelectingKeyChanged OnIsSelectingKeyChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnButtonLostFocus OnButtonLostFocus;
    
    ULocInputKeySelector();

    UFUNCTION(BlueprintCallable)
    void SetTextBlockVisibility(const ESlateVisibility InVisibility);
    
    UFUNCTION(BlueprintCallable)
    void SetSelectedKey(const FInputChord& InSelectedKey);
    
    UFUNCTION(BlueprintCallable)
    void SetNoKeySpecifiedText(FText InNoKeySpecifiedText);
    
    UFUNCTION(BlueprintCallable)
    void SetKeySelectionText(FText InKeySelectionText);
    
    UFUNCTION(BlueprintCallable)
    void SetIsSelectingKey(bool bInIsSelectingKey);
    
    UFUNCTION(BlueprintCallable)
    void SetEscapeKeys(const TArray<FKey>& InKeys);
    
    UFUNCTION(BlueprintCallable)
    void SetAllowModifierKeys(bool bInAllowModifierKeys);
    
    UFUNCTION(BlueprintCallable)
    void SetAllowGamepadKeys(bool bInAllowGamepadKeys);
    
    UFUNCTION(BlueprintCallable)
    void HandleIsSelectingKeyChanged();
    
    UFUNCTION(BlueprintCallable)
    void HandleButtonLostFocus();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsSelectingKey() const;
    
};

