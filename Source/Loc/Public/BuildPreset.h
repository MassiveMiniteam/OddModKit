#pragma once
#include "CoreMinimal.h"
#include "BuildPreset.generated.h"

class IBuildToolAssignable;
class UBuildToolAssignable;

USTRUCT(BlueprintType)
struct LOC_API FBuildPreset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsEditable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TScriptInterface<IBuildToolAssignable>> PresetItems;
    
    FBuildPreset();
};

