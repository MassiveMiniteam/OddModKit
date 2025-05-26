#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NavUserWidget.h"
#include "OnChangedValueDelegate.h"
#include "OptionsCarouselBase.generated.h"

class UStyledTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UOptionsCarouselBase : public UNavUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FText> Options;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowCircularChange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true), meta = (BindWidget))
    UStyledTextBlock* CurrentOptionText;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnChangedValue OnChange;
    
    UOptionsCarouselBase();

    UFUNCTION(BlueprintCallable)
    void SwitchRight();
    
    UFUNCTION(BlueprintCallable)
    void SwitchLeft();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetCurrentOptionByIndex_NoNotify(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentOptionByIndex(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    void ResetOptions();
    
    UFUNCTION(BlueprintCallable)
    void RenameOption(int32 Index, FText NewOptionName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentIndex() const;
    
    UFUNCTION(BlueprintCallable)
    void AddOptionFromIntPoint(FIntPoint Point);
    
    UFUNCTION(BlueprintCallable)
    void AddOption(FText Option);
    
};

