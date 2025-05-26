#pragma once
#include "CoreMinimal.h"
#include "GlossaryGameplayParagraph.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FGlossaryGameplayParagraph {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Headline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true, MultiLine=true))
    FText Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true, MultiLine=true))
    FText Description_MouseKeyboard;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true, MultiLine=true))
    FText Description_Controller;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> Image;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsInDemo;
    
    LOC_API FGlossaryGameplayParagraph();
};

