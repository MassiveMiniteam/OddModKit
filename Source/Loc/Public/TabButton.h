#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OnTabButtonClickedDelegate.h"
#include "TabButton.generated.h"

class UStyledTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UTabButton : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTabButtonClicked OnTabButtonClicked;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText ButtonText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TabIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
    UStyledTextBlock* TabHeadline;
    
public:
    UTabButton();

    UFUNCTION(BlueprintCallable)
    void UpdateButtonText(FText NewButtonText);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnTabIndexChanged(int32 NewIndex);
    
};

