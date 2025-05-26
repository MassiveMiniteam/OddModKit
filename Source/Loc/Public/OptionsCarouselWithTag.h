#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "CarouselOption.h"
#include "NavUserWidget.h"
#include "OnCarouselChangedValueDelegate.h"
#include "OptionsCarouselWithTag.generated.h"

class UStyledTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UOptionsCarouselWithTag : public UNavUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCarouselOption CurrentOption;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
    UStyledTextBlock* CurrentOptionText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCarouselOption> CarouselOptions;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCarouselChangedValue OnCarouselChange;
    
    UOptionsCarouselWithTag();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SwitchCarouselRight();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SwitchCarouselLeft();
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentOptionByTag(FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentCarouselOptionByIndex_NoNotify(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentCarouselOptionByIndex(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    void ResetOptions();
    
    UFUNCTION(BlueprintCallable)
    void ResetCarouselOptions();
    
    UFUNCTION(BlueprintCallable)
    void RemoveOptionWithTag(FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable)
    void RemoveCarouselOption(FCarouselOption OptionToRemove);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentOptionIndex() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentIndex() const;
    
    UFUNCTION(BlueprintCallable)
    void AddCarouselOptionFromIntPoint(FGameplayTag Tag, FIntPoint Point);
    
    UFUNCTION(BlueprintCallable)
    void AddCarouselOptionFromInt(FGameplayTag Tag, int32 Number);
    
    UFUNCTION(BlueprintCallable)
    void AddCarouselOption(const FCarouselOption& CarouselOption);
    
};

