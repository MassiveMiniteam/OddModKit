#pragma once
#include "CoreMinimal.h"
#include "Components/HorizontalBox.h"
#include "TabButtonRow.generated.h"

class UTabButton;
class UTabNavigation;

UCLASS(Blueprintable)
class LOC_API UTabButtonRow : public UHorizontalBox {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UTabButton*> Buttons;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTabNavigation* MyTabNavigation;
    
public:
    UTabButtonRow();

    UFUNCTION(BlueprintCallable)
    void OnTabSelected(UTabButton* Button, int32 NewIndex);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnTabIndexChanged(int32 NewIndex);
    
};

