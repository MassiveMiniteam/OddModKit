#pragma once
#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "InputKeySpriteMapping.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FInputKeySpriteMapping {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FKey Key;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Texture;
    
    LOC_API FInputKeySpriteMapping();
};

