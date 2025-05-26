#pragma once
#include "CoreMinimal.h"
#include "GlossaryGameplayParagraph.h"
#include "UnlockableDataAsset.h"
#include "GlossaryGameplayData.generated.h"

class UTexture2D;

UCLASS(Blueprintable)
class LOC_API UGlossaryGameplayData : public UUnlockableDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlossaryGameplayParagraph> Paragraphs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true, MultiLine=true))
    FText ShortDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true, MultiLine=true))
    FText ShortDescription_MouseKeyboard;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true, MultiLine=true))
    FText ShortDescription_Controller;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> PreviewImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowAsToast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SortIndex;
    
    UGlossaryGameplayData();

};

