#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DialogueSlideConfig.h"
#include "DialogueConfig.generated.h"

class USoundBase;

UCLASS(Blueprintable)
class LOC_API UDialogueConfig : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowCloseButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowAnimationSkipButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowAsSubtileOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayListeningAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDialogueSlideConfig> DialogueSlides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundBase> LoopingDialogueBackgroundSound;
    
    UDialogueConfig();

};

