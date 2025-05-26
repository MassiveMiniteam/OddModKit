#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ButtonPromptBarWidget.generated.h"

class UButtonPromptBarItemSet;
class UButtonPromptWidget;
class UHorizontalBox;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UButtonPromptBarWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsMainPromptBar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHorizontalBox* BarBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UButtonPromptWidget*> CurrentPrompts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UButtonPromptBarItemSet*> BarItemStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UButtonPromptWidget> ButtonPromptClass;
    
    UButtonPromptBarWidget();

    UFUNCTION(BlueprintCallable)
    void PushButtonPromptSet(UButtonPromptBarItemSet* ButtonPrompts);
    
    UFUNCTION(BlueprintCallable)
    void PopButtonPromptSet(UButtonPromptBarItemSet* ButtonPrompts);
    
};

