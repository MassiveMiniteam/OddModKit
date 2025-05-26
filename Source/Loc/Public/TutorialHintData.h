#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TutorialHintData.generated.h"

class UTexture2D;

UCLASS(Blueprintable)
class LOC_API UTutorialHintData : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TutorialHintHeadline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true, MultiLine=true))
    FText TutorialHintText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> TutorialIcon;
    
    UTutorialHintData();

};

