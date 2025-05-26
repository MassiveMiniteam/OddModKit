#pragma once
#include "CoreMinimal.h"
#include "Components/TextBlock.h"
#include "StyledTextBlock.generated.h"

class UTextStyle;

UCLASS(Blueprintable)
class LOC_API UStyledTextBlock : public UTextBlock {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextStyle* TextStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverwriteColor;
    
    UStyledTextBlock();

    UFUNCTION(BlueprintCallable)
    void SetTextStyle(UTextStyle* NewStyle);
    
};

