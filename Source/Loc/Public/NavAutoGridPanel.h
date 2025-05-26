#pragma once
#include "CoreMinimal.h"
#include "NavUniformGridPanel.h"
#include "NavAutoGridPanel.generated.h"

class UUniformGridSlot;
class UWidget;

UCLASS(Blueprintable)
class LOC_API UNavAutoGridPanel : public UNavUniformGridPanel {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GridWidth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxWidthCheck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxHeightCheck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableHorizontalWrapping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableVerticalWrapping;
    
    UNavAutoGridPanel();

    UFUNCTION(BlueprintCallable)
    void RefreshGridLayout();
    
    UFUNCTION(BlueprintCallable)
    UUniformGridSlot* AddChildToAutoGrid(UWidget* Content);
    
};

