#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Templates/SubclassOf.h"
#include "DialogueSlideConfig.generated.h"

class UAdditionalFullscreenDialogueWidget;
class UTexture2D;

USTRUCT(BlueprintType)
struct FDialogueSlideConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true, MultiLine=true))
    FText DialogueLine;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag Tag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAdditionalFullscreenDialogueWidget> FullScreenUserWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> FullscreenBackgroundImage;
    
    LOC_API FDialogueSlideConfig();
};

