#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SlideshowDataAsset.generated.h"

class UTexture2D;

UCLASS(Blueprintable)
class USlideshowDataAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UTexture2D>> Images;
    
    USlideshowDataAsset();

};

