#pragma once
#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "OnReceiverHoverEventDelegate.h"
#include "OnReceiverLeftClickEventDelegate.h"
#include "OnReceiverShiftLeftClickEventDelegate.h"
#include "SlateInputReceiverWidget.generated.h"

UCLASS(Blueprintable)
class LOC_API USlateInputReceiverWidget : public UWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnReceiverHoverEvent OnHovered;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnReceiverHoverEvent OnUnhovered;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnReceiverLeftClickEvent OnLeftClick;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnReceiverLeftClickEvent OnLeftClickDown;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnReceiverShiftLeftClickEvent OnShiftLeftClick;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnReceiverShiftLeftClickEvent OnCtrlLeftClick;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnReceiverHoverEvent OnMouseUp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSimulateMouseAsGamepad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* ReceiverWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSetReceiverToTreeRoot;
    
    USlateInputReceiverWidget();

};

