#pragma once
#include "CoreMinimal.h"
#include "NavUserWidget.h"
#include "OnUserInteractionDelegate.h"
#include "UserPopupWidgetData.h"
#include "UserPopupWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UUserPopupWidget : public UNavUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnUserInteraction UserAccepted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnUserInteraction UserCanceled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUserPopupWidgetData Data;
    
    UUserPopupWidget();

    UFUNCTION(BlueprintCallable)
    void Cancel();
    
    UFUNCTION(BlueprintCallable)
    void Accept();
    
};

