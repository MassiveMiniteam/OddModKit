#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RadialMenuButton.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class LOC_API URadialMenuButton : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsRadialButtonEnabled;
    
public:
    URadialMenuButton();

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnUnhover();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnHover();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnEnableStateChanged(bool bState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnClicked();
    
};

