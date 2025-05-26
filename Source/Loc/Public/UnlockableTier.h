#pragma once
#include "CoreMinimal.h"
#include "EQuestTier.h"
#include "UnlockableDataAsset.h"
#include "UnlockableTier.generated.h"

class UTexture2D;

UCLASS(Blueprintable)
class LOC_API UUnlockableTier : public UUnlockableDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EQuestTier Tier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TierName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TierSummaryText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> TierPreviewImage;
    
    UUnlockableTier();

};

